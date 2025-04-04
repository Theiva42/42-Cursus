/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:20:02 by thkumara          #+#    #+#             */
/*   Updated: 2025/04/04 16:51:02 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_simulation(t_table *table)
{
	int		i;

	printf("clean simulation No of philo - %d", table->no_of_philo);
	i = 0;
	while (i < table->no_of_philo)
			pthread_mutex_destroy(&table->forks[i++]);
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->meal_lock);
	pthread_mutex_destroy(&table->simulation_lock);
	pthread_mutex_destroy(&table->finished_lock);
	i = 0;
	if (table->no_of_philo != 1)
	{
		while (i < table->no_of_philo)
    		pthread_join(table->philo[i++].thread, NULL);
	}
	free(table->forks);
	if (table->philo)
    {
        free(table->philo);
        table->philo = NULL;
    }
    free(table);
}

void	one_philo(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(table, philo->id, "picked up left fork");
	// usleep(table->time_to_die * 1000);
	print_action(table, philo->id, "died");
	pthread_mutex_unlock(philo->left_fork);
	table->simulation_running = 0;
	cleanup_simulation(table);
	exit(0);
}

void	philo_eat(t_philo *philo, t_table *table)
{
	// pthread_mutex_lock(&table->simulation_lock);
	philo->last_meal_time = current_time();
	philo->eat_count++;
	// pthread_mutex_unlock(&table->simulation_lock);
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
	printf("Philo %d finished meals: %d\n", philo->id, philo->eat_count);
printf("Finished philosophers: %d / %d\n", table->finished_philos, table->no_of_philo);
}

void	philo_no_odd_even(t_philo *philo, t_table *table)
{
	// if (philo->id % 2 == 1)
	// 	usleep(1000 * 50);
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
		one_philo(philo, table);
	
	while (1)
	{
		pthread_mutex_lock(&table->simulation_lock);
		if (!table->simulation_running)
		{
			pthread_mutex_unlock(&table->simulation_lock);
			break;
		}
		// printf("I'm in philo routine\n");
		pthread_mutex_unlock(&table->simulation_lock);
		print_action(table, philo->id, "is thinking");
		philo_no_odd_even(philo, table);
		philo_eat(philo, table);
		print_action(table, philo->id, "is sleeping");
		usleep(table->time_to_sleep * 1000);
	}
	return (NULL);
}
