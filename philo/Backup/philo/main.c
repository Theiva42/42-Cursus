/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:15:12 by thkumara          #+#    #+#             */
/*   Updated: 2025/03/27 15:39:44 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Input Format is incorect\n");
		printf("Format: ./philo <num_philo> <time_to_die> <time_to_eat>");
		printf("<time_to_sleep>[num_times_each_philo_must_eat]\n");
		return (1);
	}
	if (check_input(argc, argv) == 0)
		return (0);
	start_simulation(argc, argv);
	return (0);
}
