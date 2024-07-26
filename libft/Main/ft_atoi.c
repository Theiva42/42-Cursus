/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:44:32 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/20 15:22:31 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<stdlib.h>

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int	num;
	int	sign;
	
	i = 0;
	num = 0;
	sign = 1;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;			
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	return (sign * num);
}

int	main (void)
{
	char *s = "\t\n\r\v\f  469 \n";
	printf("My function Output:%d\n", ft_atoi(s));
	printf("Default function Output:%d\n", atoi(s));
}
