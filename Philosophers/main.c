/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:15:12 by thkumara          #+#    #+#             */
/*   Updated: 2025/03/03 15:19:47 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Input should be: ./philo <num_philo> <time_to_die> <time_to_eat> <time_to_sleep> [num_times_each_philo_must_eat]\n");
		return (1);
	}
	start_simulation(argc, argv);
	return (0);
}
