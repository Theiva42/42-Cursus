/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:56:58 by thkumara          #+#    #+#             */
/*   Updated: 2025/04/01 22:35:34 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eaten_enough(t_table *table)
{
	pthread_mutex_lock(&table->simulation_lock);
	if (table->finished_philos == table->no_of_philo)
	{
		print_action(table, -1,
			"All philosophers have eaten enough.Stop simulation.");
		table->simulation_running = 0;
	}
		pthread_mutex_unlock(&table->simulation_lock);
}

void	check_philo_status(t_table	*table, int i)
{
	int			eaten_enough;
	long long	time_since_last_meal;

		pthread_mutex_lock(&table->meal_lock);
		time_since_last_meal = current_time() - table->philo[i].last_meal_time;
		eaten_enough = (table->num_each_philo_must_eat > 0
			&& table->philo[i].eat_count
			>= table->num_each_philo_must_eat);
			printf("num_each_philo_must_eat: %d, eat count: %d, eaten:%d\n", table->num_each_philo_must_eat, table->philo[i].eat_count, eaten_enough);
		pthread_mutex_unlock(&table->meal_lock);
		if (time_since_last_meal >= table->time_to_die)
		{
			print_action(table, table->philo[i].id, "died");
			pthread_mutex_lock(&table->simulation_lock);
			table->simulation_running = 0;
			pthread_mutex_unlock(&table->simulation_lock);
			return ;
		}
		if (eaten_enough)
		{
			pthread_mutex_lock(&table->simulation_lock);
			if (!table->philo[i].is_full)
			{
				table->philo[i].is_full = 1;
				table->finished_philos++;
			}
			pthread_mutex_unlock(&table->simulation_lock);
			printf("Philosopher %d is full. Total finished: %d/%d\n",
				i, table->finished_philos, table->no_of_philo);
		}
	philo_eaten_enough(table);	
}

void	*monitor_philosophers(void *arg)
{
	int	i;
	t_table		*table;

	table = (t_table *)arg;
	printf ("I'm monitor");
	while (1)
	{
		pthread_mutex_lock(&table->simulation_lock);
		if (!table->simulation_running)
		{
			pthread_mutex_unlock(&table->simulation_lock);
			break ;
		}
		pthread_mutex_unlock(&table->simulation_lock);
		i = 0;
		while (i < table->no_of_philo)
		{
			check_philo_status(table, i);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
