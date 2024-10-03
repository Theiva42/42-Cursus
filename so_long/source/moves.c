/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
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
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		printf("\nYou Have Won, Congrats!\n");
		exit_door(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

static int	key_up_down(t_long *game, int move)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (move == 13 || move == 126)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (move == 1 || move == 125)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
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
	if (move == 0 || move == 123)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (move == 2 || move == 124)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	printf("Moves Count: %i\n", game->counter);
	printf("Collectables Remaining: %i\n", game->collectables);
	return (1);
}

int	set_controls(int key, t_long *game)
{
	int	navigate;

	if (key == 53)
		exit_door(game);
	if (key == 13 || key == 126)
		navigate = key_up_down(game, key);
	if (key == 1 || key == 125)
		navigate = key_up_down(game, key);
	if (key == 0 || key == 123)
		navigate = key_left_right(game, key);
	if (key == 2 || key == 124)
		navigate = key_left_right(game, key);
	if (navigate)
		put_images(game);
	return (1);
}
