/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:31:01 by thkumara          #+#    #+#             */
/*   Updated: 2024/12/26 15:49:21 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

int	get_pwd(void)
{
	int		buff_size;
	char	*path;

	buff_size = 1024;
	path = malloc (sizeof(char) * 1024);
	if (path == NULL)
	{
		perror("malloc");
		return (1);
	}
	if (getcwd(path, buff_size) != NULL)
		printf("%s\n", path);
	else
		perror("getcwd");
	free (path);
	return (0);
}

int	main(int ac, char **argv)
{
	if (ac > 1)
	{
		if (ft_strcmp(argv[1], "pwd") == 0)
		{
			if (get_pwd() == 0)
				return (0);
		}
		return (1);
	}
}
