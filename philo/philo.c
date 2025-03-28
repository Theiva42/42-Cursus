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
	table->forks = malloc(sizeof(pthread_mutex_t) * no_of_philo);
	if (!table->forks)
	{
		printf("Memory allocation failed\n");
		free(table->philo);
		exit(1);
	}
	table->philo = malloc(sizeof(t_philo) * no_of_philo);
	if (!table->philo)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	pthread_mutex_init(&table->print_lock, NULL);
	pthread_mutex_init(&table->meal_lock, NULL);
	pthread_mutex_init(&table->simulation_lock, NULL);
	pthread_mutex_init(&table->finished_lock, NULL);
}

void	init_forks(t_table *table)
{
	int			i;

	i = 1;	
	while (i < table->no_of_philo)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}

}

void cleanup_simulation(t_table *table)
{
	int	i;

	i = 0;
    while (i < table->no_of_philo)
	{
        pthread_mutex_destroy(&table->forks[i]);
    	pthread_mutex_destroy(&table->print_lock);
    	pthread_mutex_destroy(&table->meal_lock);
    	pthread_mutex_destroy(&table->simulation_lock);
    	pthread_mutex_destroy(&table->finished_lock);
    	free(table->forks);
    	free(table->philo);
		i++;
	}
}
void	create_thread(t_table	*table)
{	
	int i;
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
		monitor_philosophers, (void *)&table) != 0)
	{
		printf("Error: Failed to create monitor thread\n");
		exit (1);
	}
	i = -1;
	while (++i < table->no_of_philo)
		pthread_join(table->philo[i].thread, NULL);
	pthread_join(monitor_thread, NULL);
}

void	start_simulation(int argc, char **argv)
{

	t_table		table;

	table.no_of_philo = atoi(argv[1]);
	table.time_to_die = atoi(argv[2]);
	table.time_to_eat = atoi(argv[3]);
	table.time_to_sleep = atoi(argv[4]);
	table.simulation_running = 1;
	
	init_table(&table);
    	init_forks(&table);
    	init_philo(&table, argc, argv);
	create_thread(&table);
	if (pthread_mutex_trylock(&table.print_lock) == 0)
		pthread_mutex_unlock(&table.print_lock);
	else
		printf("Warning: print_lock is still locked before destroying!\n");
	cleanup_simulation(&table);
}
