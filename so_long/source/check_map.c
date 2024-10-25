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

static void	validate_path(t_long *game, int ht, int wd)
{
	char	tile;

	if (!game->mapcpy)
	{
		if (ht < 0 || ht >= game->heightcpy || wd < 0 || wd >= game->widthcpy)
			return ;
		return ;
	}
	tile = game->mapcpy[ht][wd];
	if (tile == '1' || game->mapcpy[ht][wd] == 'F')
		return ;
	if (tile == 'C')
		game->c_flag++;
	if (tile == 'E')
		game->e_flag++;
	game->mapcpy[ht][wd] = 'F';
	validate_path(game, ht + 1, wd);
	validate_path(game, ht - 1, wd);
	validate_path(game, ht, wd + 1);
	validate_path(game, ht, wd - 1);
	return ;
}

static int	check_wall(t_long *game, int i, int j)
{
	if (i == 0)
	{
		while (i < game->heightmp)
		{
			if (!(game->map[i][0] == '1' && game->map[i][j - 1] == '1'))
				return (0);
			i++;
		}
	}
	else if (j == 0)
	{
		while (j < game->widthmp)
		{
			if (!(game->map[0][j] == '1' && game->map[i - 1][j] == '1'))
				return (0);
			j++;
		}
	}
	return (1);
}

static int	check_walls(t_long *game)
{
	int	v_wall;
	int	h_wall;

	v_wall = check_wall(game, 0, game->widthmp);
	h_wall = check_wall(game, game->heightmp, 0);
	if (!v_wall)
	{
		ft_printf("\nError in vertical wall of the Map\n");
		return (0);
	}
	if (!h_wall)
	{
		ft_printf("\nError in horizontal wall of the Map\n");
		return (0);
	}
	return (1);
}

static void	check_map_path(t_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->heightmp - 1)
	{
		j = 0;
		while (j <= game->widthmp)
		{
			if (game->map[i][j] == 'P')
			{
				game->x_axis = i;
				game->y_axis = j;
			}
			j++;
		}
		i++;
	}
	validate_path(game, game->x_axis, game->y_axis);
	if (game->c_flag != game->collcount || game->e_flag != 1)
	{
		ft_printf("\nError in Reaching the Collectables or Exit\n");
		exit_door(game);
	}
}

int	check_map(t_long *game)
{
	int	check;

	check = check_map_shape(game);
	if (check == 0)
	{
		ft_printf("\nError, Map is not in Rectangle shape\n");
		return (exit_door(game));
	}
	check = check_walls(game);
	if (check == 0)
		return (exit_door(game));
	check = check_chars(game);
	if (check == 1)
	{
		check_map_path(game);
		if (game->c_flag != game->collcount || game->e_flag != 1)
			return (exit_door(game));
	}
	else
		return (0);
	return (1);
}
