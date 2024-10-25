/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:31:26 by thkumara          #+#    #+#             */
/*   Updated: 2024/09/30 17:58:42 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	key_up(t_long *game, int i, int j)
{
	int	k;

	j--;
	if (j < 0 || game->map[j][i] == '1')
		return (0);
	if (game->map[j][i] == '1')
		return (0);
	k = right_move(game, i, j);
	if (k == 0)
		return (-1);
	if (k < 0)
		return (0);
	if (j + 1 < game->heightmp && i >= 0 && i < game->widthmp)
		game->map[j + 1][i] = '0';
	ft_printf("Moves Count: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

static int	key_down(t_long *game, int i, int j)
{
	int	k;

	j++;
	if (game->map[j][i] == '1')
		return (0);
	k = right_move(game, i, j);
	if (k == 0)
		return (-1);
	if (k < 0)
		return (0);
	if (i >= 0 && i < game->widthmp && j - 1 > 0 && j - 1 < game->heightmp)
		game->map[j - 1][i] = '0';
	ft_printf("Moves Count: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

static int	key_left(t_long *game, int i, int j)
{
	int	k;

	if (i <= 0)
		return (0);
	i--;
	if (game->map[j][i] == '1')
		return (0);
	k = right_move(game, i, j);
	if (k == 0)
		return (-1);
	if (k < 0)
		return (0);
	else if (j > 0 && j < game->heightmp)
	{	
		if (i + 1 > 0 && i + 1 < game->widthmp)
			game->map[j][i + 1] = '0';
	}
	ft_printf("Moves Count: %i\n", game->counter);
	ft_printf("Collectables Remaining: %i\n", game->collectables);
	return (1);
}

static int	key_right(t_long *game, int i, int j)
{
	int	k;

	if (i >= game->widthmp - 1)
		return (0);
	i++;
	if (j < 0 || j >= game->heightmp || game->map[j][i] == '1')
		return (0);
	k = right_move(game, i, j);
	if (k == 0)
		return (-1);
	if (k < 0)
		return (0);
	if (j >= 0 && j < game->heightmp && i - 1 >= 0 && i - 1 < game->widthmp)
		game->map[j][i - 1] = '0';
	ft_printf("Moves Count: %i\n", game->counter);
	ft_printf("Collectables Remaining: %i\n", game->collectables);
	return (1);
}

int	set_controls(int key, t_long *game)
{
	int	navigate;

	if (!game || !game->map)
		return (-1);
	if (key == 65307)
	{
		ft_printf("\nDon't Give Up, Try Again!\n");
		exit_door(game);
		exit (0);
	}
	if (key == 119 || key == 65362)
		navigate = key_up(game, game->x_axis, game->y_axis);
	if (key == 115 || key == 65364)
		navigate = key_down(game, game->x_axis, game->y_axis);
	if (key == 97 || key == 65361)
		navigate = key_left(game, game->x_axis, game->y_axis);
	if (key == 100 || key == 65363)
		navigate = key_right(game, game->x_axis, game->y_axis);
	if (navigate > 0)
		put_images(game, 0, 0);
	else if (navigate == -1)
		exit(0);
	return (1);
}
