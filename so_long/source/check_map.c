/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:49:02 by thkumara          #+#    #+#             */
/*   Updated: 2024/09/27 18:13:06 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	vertical_wall(t_long *game)
{
	int	i;
	int j;

	i = 0;
	j = game->widthmap;
	while(i < game->heightmap)
	{
		if (!(game->map[i][0] == '1' && game->map[i][j - 1] == '1'))
			return (0);
		i++;
	}
	return (1);
}

static int	horizontal_wall(t_long *game)
{
	int	i;
	int	j;

	i = game->widthmap;
	j = 0;
	while(j < i)
	{
		if (game->map[0][i] == '1' && game->map[game->heightmap - 1][j] =='1')
			return (0);	
		j++;
	}
	return (1);
}

static void check_walls(t_long *game)
{
	int	v_wall;
	int	h_wall;

	v_wall = vertical_wall(game);
	h_wall = horizontal_wall(game);
	//printf("I am here in check walls");
	if (!v_wall)
	{
		//Use ft_printf later
		printf("\nError in vertical wall of the Map\n");
		exit_door(game);
	}
	if (!h_wall)
	{
		//Use ft_printf later
		printf("\nError in horizontal wall of the Map\n");
		exit_door(game);
	}
}
static void check_count(t_long *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
			game->map[height][width] != '0' &&
			game->map[height][width] != 'P' &&
			game->map[height][width] != 'E' &&
			game->map[height][width] != 'C' &&
			game->map[height][width] != '\n')
	{
		printf("\nError in %c\n", game->map[height][width]);
		exit_door(game);
	}
	if (game->map[height][width] == 'P')
		game->playercount++;
	if (game->map[height][width] == 'C')
		game->columncount++;
	if (game->map[height][width] == 'E')
		game->exitcount++;
	//printf("%i, %i, %i", game->playercount, game->columncount, game->exitcount);
}

static void	check_chars(t_long *game)
{
	int height;
	int width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			check_count(game, height, width);
			width++;
		}
		height++;
	}
	//printf("%i", game->heightmap);
	if (!(game->playercount == 1 && game->columncount > 1 && game->exitcount == 1))
	{
		//printf("%i, %i, %i", game->playercount, game->columncount, game->exitcount);
		printf("\nError in Player or Collectables or Exit\n");
		exit_door(game);
	}
}

void	check_map(t_long *game)
{
	//printf("I am here in check map");
	check_walls(game);
	check_chars(game);
}
