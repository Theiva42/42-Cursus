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

void	*philosopher_routine(void *arg)
{
	t_philo *philo = (t_philo *) arg;
	printf("Philosopher %d is thinking... \n", philo->id);
	return(NULL);
}

void	start_simulation(int argc, char **argv)
{
	int num_philo;
	int i;
	t_philo philos[num_philo];

	num_philo = atoi(argv[1]);
	i = 0;
	while (i < num_philo)
	{
		philos[i].id = i + 1;
		pthread_create(&philos[i].thread, NULL, philosopher_routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < num_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}
