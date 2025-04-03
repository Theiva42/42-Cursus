/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:32:09 by thkumara          #+#    #+#             */
/*   Updated: 2025/04/03 14:03:23 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(int argc, char **argv)
{
	int	i;
	int	value;

	i = 1;
	while (i < argc)
	{
		value = atoi(argv[i]);
		if (!ft_isnum(argv[i]))
		{
			printf("Input should be valid number\n");
			return (0);
		}
		if (value <= 0)
		{
			printf("Input should not have negative values or zero\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long long	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

void	print_action(t_table *table, int id, char *action)
{
	if (!table)
	{
		pthread_mutex_lock(&table->print_lock);
		printf("Error: print_action() received NULL table!\n");
		pthread_mutex_unlock(&table->print_lock);
		return ;
	}
	if (table->simulation_running)
	{
		pthread_mutex_lock(&table->print_lock);
		printf("[%lld] Philosopher %d %s\n", current_time(), id, action);
		pthread_mutex_unlock(&table->print_lock);
	}
}
