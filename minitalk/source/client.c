/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:02:53 by thkumara          #+#    #+#             */
/*   Updated: 2024/11/03 16:29:18 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	ft_to_bits(pid_t pid, char c)
{
	int	pos;

	pos = 0;
	while (pos < 8)
	{
		if ((c & (0x01 << pos)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		pos++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			ft_printf("Error: Invalid PID\n");
			return (1);
		}
		msg = argv[2];
		while (*msg != '\0')
		{
			ft_to_bits(pid, *msg);
			msg++;
		}
		ft_to_bits(pid, '\0');
	}
	else
	{
		ft_printf("Error\nTry again:./client <PID> <MESSAGE>\n");
		return (1);
	}
	return (0);
}
