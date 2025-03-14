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
	t_table *table = philo->table;

	if (table->no_of_philo == 1) {
        pthread_mutex_lock(philo->left_fork);
        print_action(table, philo->id, "picked up left fork (only one, will die)");
        usleep(table->time_to_die * 1000); 
        print_action(table, philo->id, "died");
        pthread_mutex_unlock(philo->left_fork);
		table->simulation_running = 0;
        return NULL;
    }

    while (table->simulation_running)
    {
        print_action(table, philo->id, "is thinking");
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

		pthread_mutex_lock(&table->meal_lock);
		philo->last_meal_time = current_time();
		philo->eat_count++;
		pthread_mutex_unlock(&table->meal_lock);

        print_action(table, philo->id, "is eating");
		
        usleep (1000 * 200);

        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);

		if (table->num_times_each_philosopher_must_eat > 0 && 
            philo->eat_count >= table->num_times_each_philosopher_must_eat) {
				print_action(table, -1, "All philosophers have eaten enough. Stopping simulation.");
				table->simulation_running = 0;
				return NULL;
        }

        print_action(table, philo->id, "is sleeping");
        usleep(1000 * 200);

    }
    return NULL;
}

void *monitor_philosophers(void *arg)
{
	t_table	*table = (t_table *)arg;
	long long time_since_last_meal;
	int finished_philosophers = 0;
	int i;

	i = 0;
	while(table->simulation_running)
	{
		finished_philosophers = 0;
		while (i < table->no_of_philo)
		{
			pthread_mutex_lock(&table->meal_lock);
			time_since_last_meal = current_time() - table->philo[i].last_meal_time;
			pthread_mutex_unlock(&table->meal_lock);
			int eaten_enough = (table->num_times_each_philosopher_must_eat > 0 &&
				table->philo[i].eat_count >= table->num_times_each_philosopher_must_eat);

			if (time_since_last_meal >= table->time_to_die)
			{
				print_action(table, table->philo[i].id, "died");
				table->simulation_running = 0;
				return NULL;
			}
			if (eaten_enough)
                finished_philosophers++;
			if (finished_philosophers == table->no_of_philo)
			{
				print_action(table, -1, "All philosophers have eaten enough. Stopping simulation.");
				table->simulation_running = 0;
				return NULL;
			}
			i++;
		}
		usleep(1000 * 10);
	}
	return NULL;
}

void	start_simulation(int argc, char **argv)
{
	int no_of_philo;
	int time_to_die;
	int i;
	t_table	table;
	pthread_t monitor_thread;

	no_of_philo = atoi(argv[1]);
	time_to_die = atoi(argv[2]);

	i = 1;
	table.no_of_philo = no_of_philo;
	table.time_to_die = time_to_die;
	table.simulation_running = 1;

	table.forks = malloc(sizeof(pthread_mutex_t) * no_of_philo);
	table.philo = malloc(sizeof(t_philo) * no_of_philo);
	
	pthread_mutex_init(&table.print_lock, NULL);
	pthread_mutex_init(&table.meal_lock, NULL);

	while (i < table.no_of_philo)
	{
		pthread_mutex_init(&table.forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < table.no_of_philo)
	{
		table.philo[i].id = i + 1;
		table.philo[i].left_fork = &table.forks[i];
		table.philo[i].right_fork = &table.forks[(i + 1) % no_of_philo];
		table.philo[i].table = &table;
		table.philo[i].last_meal_time = current_time();
		if (argc == 6)
			table.num_times_each_philosopher_must_eat = atoi(argv[5]);
		
		printf("Philosopher %d initialized: left_fork=%p, right_fork=%p, table=%p\n",
		table.philo[i].id, (void*)table.philo[i].left_fork, 
		(void*)table.philo[i].right_fork, (void*)table.philo[i].table);
		
		pthread_create(&table.philo[i].thread, NULL, philosopher_routine, (void *)&table.philo[i]);
		i++;
	}

	pthread_create(&monitor_thread, NULL, monitor_philosophers, &table);
	pthread_join(monitor_thread, NULL);

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
	pthread_mutex_destroy(&table.meal_lock);

	free (table.forks);
	free (table.philo);
}
