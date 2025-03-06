/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:24:44 by thkumara          #+#    #+#             */
/*   Updated: 2025/03/03 15:56:23 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void    *philosopher_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    while (1)
    {
        print_action(NULL, philo->id, "is thinking");
		if (philo->id % 2 == 1)
			usleep(1000 * 50);
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->right_fork);
     		print_action(NULL, philo->id, "picked up right fork");
        	pthread_mutex_lock(philo->left_fork);
        	print_action(NULL, philo->id, "picked up left fork");
		}
		else
		{
			pthread_mutex_lock(philo->left_fork);
        	print_action(NULL, philo->id, "picked up left fork");
			pthread_mutex_lock(philo->right_fork);
     		print_action(NULL, philo->id, "picked up right fork");
		}

        print_action(NULL, philo->id, "is eating");
        usleep (1000 * 200);

        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);

        print_action(NULL, philo->id, "is sleeping");
        usleep(1000 * 200);
    }
    return NULL;
}

void	start_simulation(int argc, char **argv)
{
	int no_of_philo;
	int i;
	t_table	table;

	no_of_philo = atoi(argv[1]);
	i = 1;
	table.no_of_philo = no_of_philo;
	table.forks = malloc(sizeof(pthread_mutex_t) * no_of_philo);
	table.philo = malloc(sizeof(t_philo) * no_of_philo);
	
	pthread_mutex_init(&table.print_lock, NULL);

	while (i < table.no_of_philo)
	{
		pthread_mutex_init(&table.forks[i], NULL);
		i++;
	}
	i = 1;
	while (i < table.no_of_philo)
	{
		table.philo[i].id = i + 1;
		table.philo[i].left_fork = &table.forks[i];
		table.philo[i].right_fork = &table.forks[(i + 1) % no_of_philo];
		pthread_create(&table.philo[i].thread, NULL, philosopher_routine, (void *)&table.philo[i]);
		i++;
	}
	i = 1;
	while (i < table.no_of_philo)
	{
		pthread_join(table.philo[i].thread, NULL);
		i++;
	}
	i = 1;
	while (i < table.no_of_philo)
	{
		pthread_mutex_destroy(&table.forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table.print_lock);
	free (table.forks);
	free (table.philo);
}
