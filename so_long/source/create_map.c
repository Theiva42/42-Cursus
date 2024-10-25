/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:08:13 by thkumara          #+#    #+#             */
/*   Updated: 2024/09/27 16:42:08 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_long *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmp++;
	temp = (char **)malloc(sizeof(char *) * (game->heightmp + 1));
	if (!temp)
		return (0);
	while (i < game->heightmp - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	temp[game->heightmp] = NULL;
	if (game->map)
	{
		free(game->map);
		game->map = NULL;
	}
	game->map = temp;
	return (1);
}

static int	add_linecpy(t_long *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightcpy++ ;
	temp = (char **)malloc(sizeof(char *) * (game->heightcpy + 1));
	if (!temp)
		return (0);
	while (i < game->heightcpy - 1)
	{
		temp[i] = game->mapcpy[i];
		i++;
	}
	temp[i] = line;
	temp[game->heightcpy] = NULL;
	if (game->mapcpy)
	{
		free(game->mapcpy);
		game->mapcpy = NULL;
	}
	game->mapcpy = temp;
	return (1);
}

int	create_mapcpy(t_long *game, char **argv)
{
	char	*mapcpy;
	int		line;

	game->fd = open (argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		mapcpy = get_next_line(game->fd);
		if (!mapcpy)
			break ;
		line = add_linecpy(game, mapcpy);
		if (!line)
		{
			free (mapcpy);
			break ;
		}
	}
	close (game->fd);
	if (game->heightcpy > 0)
		game->widthcpy = width_of_map(game->mapcpy[0]);
	else
		game->widthcpy = 0;
	return (1);
}

int	create_map(t_long *game, char **argv)
{
	char	*map;
	int		line;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		ft_printf("Error: Cannot open Map file. %d\n", game->fd);
		return (0);
	}
	while (1)
	{
		map = get_next_line(game->fd);
		line = add_line(game, map);
		if (!line)
		{
			free (map);
			break ;
		}
	}
	close (game->fd);
	if (game->heightmp > 0)
		game->widthmp = width_of_map(game->map[0]);
	else
		game->widthmp = 0;
	return (1);
}
