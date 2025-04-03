/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:24:44 by thkumara          #+#    #+#             */
/*   Updated: 2025/03/25 16:11:42 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_table(t_table *table)
{
	table->forks = malloc(sizeof(pthread_mutex_t) * table->no_of_philo);
	if (!table->forks)
	{
		printf("Memory allocation failed\n");
		free(table->philo);
		exit(1);
	}
	table->philo = malloc(sizeof(t_philo) * table->no_of_philo);
	if (!table->philo)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	pthread_mutex_init(&table->print_lock, NULL);
	pthread_mutex_init(&table->meal_lock, NULL);
	pthread_mutex_init(&table->simulation_lock, NULL);
	pthread_mutex_init(&table->finished_lock, NULL);
	table->simulation_running = 1;
	table->finished_philos = 0;
}

void	init_forks(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->no_of_philo)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}

void	cleanup_simulation(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->no_of_philo)
		pthread_mutex_destroy(&table->forks[i++]);
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->meal_lock);
	pthread_mutex_destroy(&table->simulation_lock);
	pthread_mutex_destroy(&table->finished_lock);
	i = 0;
	while (i < table->no_of_philo)
	{
    	pthread_join(table->philo[i].thread, NULL);
		i++;
	}
	free(table->forks);
	if (table->philo)
    {
        free(table->philo);
        table->philo = NULL;
    }
    free(table);
}

void	create_thread(t_table	*table)
{
	int			i;
	pthread_t	monitor_thread;

	i = 0;
	while (i < table->no_of_philo)
	{
		if (pthread_create(&table->philo[i].thread,
				NULL, philosopher_routine, (void *)&table->philo[i]) != 0)
		{
			printf("Error: Failed to create philosopher thread %d\n", i + 1);
			exit (1);
		}
		i++;
	}
	if (pthread_create(&monitor_thread, NULL,
			monitor_philosophers, (void *)table) != 0)
	{
		printf("Error: Failed to create monitor thread\n");
		exit (1);
	}
	i = 0;
	while (i < table->no_of_philo)
	{
		if (pthread_join(table->philo[i].thread, NULL) != 0)
		{
			printf("Error joining philosopher thread %d\n", i);
			exit (1);
		}
		i++;
	}
	if (pthread_join(monitor_thread, NULL) != 0)
	{
		printf("Error joining monitor thread\n");
        exit(1);
	}
}

void	start_simulation(int argc, char **argv)
{
	t_table		table;

	table.no_of_philo = ft_atoi(argv[1]);
	table.time_to_die = ft_atoi(argv[2]);
	table.time_to_eat = ft_atoi(argv[3]);
	table.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
			table.num_each_philo_must_eat = ft_atoi(argv[5]);
	init_table(&table);
	// printf("table.num_each_philo_must_eat: %d\n", table.num_each_philo_must_eat);
	init_forks(&table);
	init_philo(&table);
	create_thread(&table);
	// if (!pthread_mutex_unlock(&table.print_lock))
	// 	printf("Warning: print_lock is still locked before destroying!\n");
	cleanup_simulation(&table);
}
