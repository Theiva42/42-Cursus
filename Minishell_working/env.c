/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:04:17 by thkumara          #+#    #+#             */
/*   Updated: 2024/12/27 15:10:51 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<stdlib.h>

void	print_env_var(char **envp)
{
	while (*envp != NULL)
	{
		printf ("%s\n", *envp);
		envp++;
	}
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	
	print_env_var(envp);
	return (0);
}
