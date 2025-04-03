/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:56:58 by thkumara          #+#    #+#             */
/*   Updated: 2025/04/03 19:16:20 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	return (sign * num);
}

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
			&& table->philo[i].eat_count == table->num_each_philo_must_eat);
	printf("num_each_philo_must_eat: %d, eat count: %d, eaten:%d\n",
	 		table->num_each_philo_must_eat, table->philo[i].eat_count, eaten_enough);
	pthread_mutex_unlock(&table->meal_lock);
	pthread_mutex_lock(&table->simulation_lock);
	if (!table->simulation_running)
	{
		pthread_mutex_unlock(&table->simulation_lock);
		return;
	}
	if (time_since_last_meal >= table->time_to_die)
	{
		print_action(table, table->philo[i].id, "died");
		table->simulation_running = 0;
		return ;
	}
	if (eaten_enough && !table->philo[i].is_full)
	{
		pthread_mutex_lock(&table->simulation_lock);
		table->philo[i].is_full = 1;
		table->finished_philos++;
		pthread_mutex_unlock(&table->simulation_lock);
	}
	// printf("Philosopher %d is full. Total finished: %d/%d\n",
	// 	i, table->finished_philos, table->no_of_philo);
	philo_eaten_enough(table);
}

void	*monitor_philosophers(void *arg)
{
	int			i;
	t_table		*table;

	table = (t_table *)arg;
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
		usleep(10000);
	}
	return (NULL);
}
