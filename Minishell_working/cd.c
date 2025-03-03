/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:40:43 by thkumara          #+#    #+#             */
/*   Updated: 2024/12/27 17:57:06 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

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

void	change_dir(char *path)
{
	char	cwd[1024];
	int	cd;
	char	*home;
	if (path == NULL || ft_strcmp(path, "") == 0)
	{
		home = getenv("HOME");
		if (home != NULL)
			path = home;
		else
			printf("cd: No home directory set: %s\n", home);
		return;
	}
	getcwd(cwd, sizeof(cwd));
	printf ("Current directory: %s\n", cwd);
	cd = chdir(path);
	if (cd == -1)
			perror("cd");
	else
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf ("pwd: %s\n", cwd);
		else
			perror("getcwd");
	}
}

int	main(void)
{
	char *path = "new";
	change_dir(path);
	return (0);
}


