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
}

void	philo_eat(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(&table->meal_lock);
	philo->last_meal_time = current_time();
	philo->eat_count++;
	pthread_mutex_unlock(&table->meal_lock);
	print_action(table, philo->id, "is eating");
	usleep (table->time_to_eat * 1000);
	pthread_mutex_lock(&table->meal_lock);
	if (table->num_times_each_philosopher_must_eat > 0
		&& philo->eat_count >= table->num_times_each_philosopher_must_eat)
	{
		pthread_mutex_unlock(&table->meal_lock);
		pthread_mutex_lock(&table->finished_lock);
		table->finished_philosophers++;
		if (table->finished_philosophers == table->no_of_philo)
		{
			pthread_mutex_lock(&table->simulation_lock);
			table->simulation_running = 0;
			pthread_mutex_unlock(&table->simulation_lock);
		}
		pthread_mutex_unlock(&table->finished_lock);
	}
	else
		pthread_mutex_unlock(&table->meal_lock);
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
	while (table->simulation_running)
	{
		pthread_mutex_unlock(&table->simulation_lock);
		print_action(table, philo->id, "is thinking");
		philo_no_odd_even(philo, table);
		philo_eat(philo, table);
		pthread_mutex_lock(&table->simulation_lock);
	}
	pthread_mutex_unlock(&table->simulation_lock);
	print_action(table, philo->id, "is sleeping");
	usleep(table->time_to_sleep * 1000);
	return (NULL);
}

void	*monitor_philosophers(void *arg)
{
	int			finished_philosophers;
	int			i;
	int			eaten_enough;
	t_table		*table;
	long long	time_since_last_meal;

	table = (t_table *)arg;
	pthread_mutex_lock(&table->simulation_lock);
	while (table->simulation_running)
	{
		pthread_mutex_unlock(&table->simulation_lock);
		finished_philosophers = 0;
		i = 0;
		while (i < table->no_of_philo)
		{
			pthread_mutex_lock(&table->meal_lock);
			time_since_last_meal = current_time()
				- table->philo[i].last_meal_time;
			eaten_enough = (table->num_times_each_philosopher_must_eat > 0
					&& table->philo[i].eat_count
					>= table->num_times_each_philosopher_must_eat);
			pthread_mutex_unlock(&table->meal_lock);
			if (time_since_last_meal >= table->time_to_die)
			{
				print_action(table, table->philo[i].id, "died");
				pthread_mutex_lock(&table->simulation_lock);
				table->simulation_running = 0;
				pthread_mutex_unlock(&table->simulation_lock);
				return (NULL);
			}
			if (eaten_enough)
				finished_philosophers++;
			i++;
		}
		if (finished_philosophers == table->no_of_philo)
		{
			print_action(table, -1,
				"All philosophers have eaten enough.Stop simulation.");
			pthread_mutex_lock(&table->simulation_lock);
			table->simulation_running = 0;
			pthread_mutex_unlock(&table->simulation_lock);
			return (NULL);
		}
		usleep(10000);
		pthread_mutex_lock(&table->simulation_lock);
	}
	pthread_mutex_unlock(&table->simulation_lock);
	return (NULL);
}

void	start_simulation(int argc, char **argv)
{
	int			no_of_philo;
	int			time_to_die;
	int			time_to_sleep;
	int			time_to_eat;
	int			i;
	t_table		table;
	pthread_t	monitor_thread;

	no_of_philo = atoi(argv[1]);
	time_to_die = atoi(argv[2]);
	time_to_eat = atoi(argv[3]);
	time_to_sleep = atoi(argv[4]);
	i = 1;
	table.no_of_philo = no_of_philo;
	table.time_to_die = time_to_die;
	table.time_to_eat = time_to_eat;
	table.time_to_sleep = time_to_sleep;
	table.simulation_running = 1;
	table.forks = malloc(sizeof(pthread_mutex_t) * no_of_philo);
	if (!table.forks)
	{
		printf("Memory allocation failed\n");
		free(table.philo);
		exit(1);
	}
	table.philo = malloc(sizeof(t_philo) * no_of_philo);
	if (!table.philo)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	pthread_mutex_init(&table.print_lock, NULL);
	pthread_mutex_init(&table.meal_lock, NULL);
	pthread_mutex_init(&table.simulation_lock, NULL);
	pthread_mutex_init(&table.finished_lock, NULL);
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
		if (pthread_create(&table.philo[i].thread,
				NULL, philosopher_routine, (void *)&table.philo[i]) != 0)
		{
			printf("Error: Failed to create philosopher thread %d\n", i + 1);
			if (pthread_mutex_trylock(&table.print_lock) != 0)
				pthread_mutex_destroy(&table.print_lock);
			if (pthread_mutex_trylock(&table.meal_lock) != 0)
				pthread_mutex_destroy(&table.meal_lock);
			if (pthread_mutex_trylock(&table.simulation_lock) != 0)
				pthread_mutex_destroy(&table.simulation_lock);
			if (pthread_mutex_trylock(&table.finished_lock) != 0)
				pthread_mutex_destroy(&table.finished_lock);
			exit (1);
		}
		i++;
	}
	if (pthread_create(&monitor_thread, NULL,
			monitor_philosophers, (void *)&table) != 0)
	{
		printf("Error: Failed to create monitor thread\n");
		if (pthread_mutex_trylock(&table.print_lock) != 0)
			pthread_mutex_destroy(&table.print_lock);
		if (pthread_mutex_trylock(&table.meal_lock) != 0)
			pthread_mutex_destroy(&table.meal_lock);
		if (pthread_mutex_trylock(&table.simulation_lock) != 0)
			pthread_mutex_destroy(&table.simulation_lock);
		if (pthread_mutex_trylock(&table.finished_lock) != 0)
			pthread_mutex_destroy(&table.finished_lock);
		exit (1);
	}
	i = 0;
	while (i < table.no_of_philo)
	{
		pthread_join(table.philo[i].thread, NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
	if (pthread_mutex_trylock(&table.print_lock) == 0)
		pthread_mutex_unlock(&table.print_lock);
	else
		printf("Warning: print_lock is still locked before destroying!\n");
	i = 0;
	while (i < table.no_of_philo)
	{
		pthread_mutex_destroy(&table.forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table.print_lock);
	pthread_mutex_destroy(&table.meal_lock);
	pthread_mutex_destroy(&table.simulation_lock);
	pthread_mutex_destroy(&table.finished_lock);
	free (table.forks);
	free (table.philo);
}
