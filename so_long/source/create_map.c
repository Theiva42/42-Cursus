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
	char **temp;
	int	i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temp = (char**)malloc(sizeof(char *) * (game->heightmap + 1));
	if (!temp)
		return (0);
	temp[game->heightmap] = NULL;
	printf("height: %d\n",game->heightmap);
	while (i < game->heightmap - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int create_map(t_long *game, char **argv)
{
	char	*map;

	game->fd = open(argv[1], O_RDONLY);
	printf("argv:%s\n", argv[1]);
	if (game->fd < 0)
	{
		printf("Error: Cannot open Map file. %d\n", game->fd);
		return(0);
	}
	while (game->fd)
	{
		map = get_next_line(game->fd);
		if (!add_line(game, map))
		{ 
			printf("I am stopping while properly");
			break ;
		}
	}
	close (game->fd);
	game->widthmap = width_of_map(game->map[0]);
	printf("Map width: %d, height: %d\n", game->widthmap, game->heightmap);
	return(1);
}
