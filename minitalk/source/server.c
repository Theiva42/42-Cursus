/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:06:43 by thkumara          #+#    #+#             */
/*   Updated: 2024/11/03 16:31:28 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	ft_sig_handler(int sig)
{
	static int	pos = 0;
	static int	i = 0;

	if (sig == SIGUSR1)
		i |= (0x01 << pos);
	pos++;
	if (pos == 8)
	{
		if (i == '\0')
			ft_printf("\nEnd of message\n");
		else
			ft_printf("%c", i);
		pos = 0;
		i = 0;
	}
}

void	set_sig_handle(void)
{
	struct sigaction	sa;

	sa.sa_handler = ft_sig_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		ft_printf("Try again: ./server\n");
		return (1);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	set_sig_handle();
	while (1)
	{
		pause();
	}
	return (0);
}
