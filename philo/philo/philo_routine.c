/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:20:02 by thkumara          #+#    #+#             */
/*   Updated: 2025/04/03 19:48:03 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_table *table)
{
	int			i;

	i = 0;
	while (i < table->no_of_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].eat_count = 0;
		table->philo[i].is_full = 0;
		table->philo[i].left_fork = &table->forks[i];
		table->philo[i].right_fork = &table->forks[(i + 1)
			% table->no_of_philo];
		table->philo[i].table = table;
		table->philo[i].last_meal_time = current_time();
		memset(&table->philo[i].thread, 0, sizeof(pthread_t));
		i++;
	}
}

void	one_philo(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(table, philo->id, "picked up left fork");
	usleep(table->time_to_die * 1000);
	print_action(table, philo->id, "died");
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_lock(&table->simulation_lock);
	table->simulation_running = 0;
	pthread_mutex_unlock(&table->simulation_lock);
	cleanup_simulation(table);
	exit(0);
}

void	philo_eat(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(&table->simulation_lock);
	philo->last_meal_time = current_time();
	philo->eat_count++;
	pthread_mutex_unlock(&table->simulation_lock);
	print_action(table, philo->id, "is eating");
	usleep (table->time_to_eat * 1000);
	pthread_mutex_lock(&table->meal_lock);
	if (table->num_each_philo_must_eat > 0
		&& philo->eat_count == table->num_each_philo_must_eat)
		table->finished_philos++;
	pthread_mutex_unlock(&table->meal_lock);
	pthread_mutex_lock(&table->finished_lock);
	if (table->finished_philos == table->no_of_philo)
	{
		pthread_mutex_lock(&table->simulation_lock);
		table->simulation_running = 0;
		pthread_mutex_unlock(&table->simulation_lock);
	}
	pthread_mutex_unlock(&table->finished_lock);
}

void	philo_no_odd_even(t_philo *philo, t_table *table)
{
	if (philo->id % 2 == 1)
		usleep(1000 * 50);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(table, philo->id, "picked up right fork");
		pthread_mutex_lock(philo->left_fork);
		print_action(table, philo->id, "picked up left fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(table, philo->id, "picked up left fork");
		pthread_mutex_lock(philo->right_fork);
		print_action(table, philo->id, "picked up right fork");
	}
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = philo->table;
	if (table->no_of_philo == 1)
		return (one_philo(philo, table), NULL);
	pthread_mutex_lock(&table->simulation_lock);
	if (table->simulation_running)
	{
		while (table->simulation_running)
		{
			pthread_mutex_unlock(&table->simulation_lock);
			print_action(table, philo->id, "is thinking");
			philo_no_odd_even(philo, table);
			philo_eat(philo, table);
			pthread_mutex_lock(&table->simulation_lock);
		}
		pthread_mutex_unlock(&table->simulation_lock);
	}
	else
		pthread_mutex_unlock(&table->simulation_lock);
	print_action(table, philo->id, "is sleeping");
	usleep(table->time_to_sleep * 1000);
	return (NULL);
}
