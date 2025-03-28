/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:56:58 by thkumara          #+#    #+#             */
/*   Updated: 2025/03/28 15:00:40 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	philo_eaten_enough(int finished_philos, t_table *table)
{
	if (finished_philos == table->no_of_philo)
	{
		print_action(table, -1,
			"All philosophers have eaten enough.Stop simulation.");
		pthread_mutex_lock(&table->simulation_lock);
		table->simulation_running = 0;
		pthread_mutex_unlock(&table->simulation_lock);
	}
	return ;
}

void	check_philo_status(t_table	*table, int finished_philos)
{
	int			i;
	int			eaten_enough;
	long long	time_since_last_meal;

	finished_philos = 0;
	i = 0;
	while (i < table->no_of_philo)
	{
		pthread_mutex_lock(&table->meal_lock);
		time_since_last_meal = current_time() - table->philo[i].last_meal_time;
		eaten_enough = (table->num_each_philo_must_eat > 0
				&& table->philo[i].eat_count >= table->num_each_philo_must_eat);
		pthread_mutex_unlock(&table->meal_lock);
		if (time_since_last_meal >= table->time_to_die)
		{
			print_action(table, table->philo[i].id, "died");
			pthread_mutex_lock(&table->simulation_lock);
			table->simulation_running = 0;
			pthread_mutex_unlock(&table->simulation_lock);
		}
		if (eaten_enough)
			finished_philos++;
		i++;
	}
	philo_eaten_enough(finished_philos, table);
}

void	*monitor_philosophers(void *arg)
{
	int			finished_philos;
	t_table		*table;

	table = (t_table *)arg;
	finished_philos = 0;
	pthread_mutex_lock(&table->simulation_lock);
	while (table->simulation_running)
	{
		pthread_mutex_unlock(&table->simulation_lock);
		check_philo_status(table, finished_philos);
		if (finished_philos == table->no_of_philo)
		{
			pthread_mutex_lock(&table->simulation_lock);
			table->simulation_running = 0;
			pthread_mutex_unlock(&table->simulation_lock);
		}
		pthread_mutex_lock(&table->simulation_lock);
		usleep(10000);
	}
	pthread_mutex_unlock(&table->simulation_lock);
	return (NULL);
}
