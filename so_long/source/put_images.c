/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:14:22 by thkumara          #+#    #+#             */
/*   Updated: 2024/09/27 18:45:41 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	place_player(t_long *game, int height, int width)
{
	mlx_put_image_to_window(game->newmlx,
		game->mywindow, game->player, width * 50, height * 50);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_collectable(t_long *game, int height, int width)
{
	mlx_put_image_to_window(game->newmlx,
		game->mywindow, game->collect, width * 50, height * 50);
	game->collectables++;
}

void	create_images(t_long *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->newmlx, "asset/F.xpm", &i, &j);
	game->blocks = mlx_xpm_file_to_image(game->newmlx, "asset/T.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->newmlx, "asset/P.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->newmlx, "asset/E.xpm", &i, &j);
	game->collect = mlx_xpm_file_to_image(game->newmlx, "asset/C.xpm", &i, &j);
}

void	put_images(t_long *game, int height, int width)
{
	game->collectables = 0;
	height = 0;
	while (height < game->heightmp)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->newmlx,
					game->mywindow, game->blocks, width * 50, height * 50);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->newmlx,
					game->mywindow, game->exit, width * 50, height * 50);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->newmlx,
					game->mywindow, game->floor, width * 50, height * 50);
			width++;
		}
		height++;
	}
}
