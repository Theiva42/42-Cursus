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
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("Input Format: ./philo <num_philo> <time_to_die> <time_to_eat> <time_to_sleep> [num_times_each_philo_must_eat]\n");
		return (1);
	}
	i = 1;
	// while (i <= argc)
	// {
	// 	if (ft_strcmp(argv[i], " ") != 0)
	// 	{
	// 		printf("Input should not be empty\n");
	// 		printf("Input Format: ./philo <num_philo> <time_to_die> <time_to_eat> <time_to_sleep> [num_times_each_philo_must_eat]\n");
	// 		break;
	// 	}
	// 	if (argv[i] <= 0)
	// 	{
	// 		printf("Input should not have negative values or zero\n");
	// 		break;
	// 	}		
	// 	if (ft_isdigit(atoi(argv[i])) != 0)
	// 	{
	// 		printf("Input should be valid number\n");
	// 		break;
	// 	}		
	// 	i++;
	// }
	start_simulation(argc, argv);
	return (0);
}
