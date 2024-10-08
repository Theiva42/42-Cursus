/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_controls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:31:26 by thkumara          #+#    #+#             */
/*   Updated: 2024/09/30 17:58:42 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	right_move(t_long *game, int i, int j)
{
    if (j < 0 || j >= game->heightmap || i < 0 || i >= game->widthmap)
        return (-1);
	else if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		printf("\nYou Have Won, Congrats!\n");
		exit_door(game);
	}
	else if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	else if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectables--;
		game->counter++;
	}
	else
		return (-1);
	return (1);
}

static int	key_up_down(t_long *game, int move)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (move == 119 || move == 65362)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (k <= 0)
			return (0);
		if (!(j < 0 || j >= game->heightmap || i < 0 || i >= game->widthmap))
			game->map[j + 1][i] = '0';
	}
	else if (move == 115 || move == 65364)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (k <= 0)
			return (0);
		if (!(j <= 0 || j >= game->heightmap || i < 0 || i >= game->widthmap))
			game->map[j - 1][i] = '0';
	}
	printf("Moves Count: %i\n", game->counter);
	printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

static int	key_left_right(t_long *game, int move)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (move == 97 || move == 65361)
	{
		if (i <= 0)
			return (0);
		i--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (k <= 0)
			return (0);
	 	 if (!(j < 0 && j > game->heightmap && i + 1 < 0 && i + 1 > game->widthmap))
			game->map[j][i + 1] = '0';
	}
	else if (move == 100 || move == 65363)
	{
		if (i >= game->widthmap - 1)
			return (0);
		i++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (k <= 0)
			return (0);
		if (!(j < 0 && j > game->heightmap && i - 1 < 0 && i - 1 > game->widthmap))
			game->map[j][i - 1] = '0';
	}
	printf("Moves Count: %i\n", game->counter);
	printf("Collectables Remaining: %i\n", game->collectables);
	return (1);
}

int	set_controls(int key, t_long *game)
{
	int	navigate;

	if (!game || !game->map)
        return (-1);
	if (key == 65307)
		exit_door(game);
	if (key == 119 || key == 65362)
	{
		navigate = key_up_down(game, key);
		//printf("Going to key up down");
	}
	if (key == 115 || key == 65364)
		navigate = key_up_down(game, key);
	if (key == 97 || key == 65361)
		navigate = key_left_right(game, key);
	if (key == 100 || key == 65363)
		navigate = key_left_right(game, key);
	if (navigate)
		put_images(game);
	return (1);
}
