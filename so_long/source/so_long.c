/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:08:10 by thkumara          #+#    #+#             */
/*   Updated: 2024/09/27 14:07:47 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	free_map(t_long *game)
{
	int	i;

	i = -1;
	if (game->map)
	{
		while (game->map[++i])
		{
			free(game->map[i]);
			game->map[i] = NULL;
		}
		free(game->map);
		game->map = NULL;
	}
	if (game->mapcpy)
	{
		i = -1;
		while (game->mapcpy[++i])
		{
			free(game->mapcpy[i]);
			game->mapcpy[i] = NULL;
		}
		free(game->mapcpy);
		game->mapcpy = NULL;
	}
}

static void	free_image(t_long *game)
{
	if (game->player)
	{
		mlx_destroy_image(game->newmlx, game->player);
		game->player = NULL;
	}
	if (game->collect)
	{
		mlx_destroy_image(game->newmlx, game->collect);
		game->collect = NULL;
	}
	if (game->exit)
	{
		mlx_destroy_image(game->newmlx, game->exit);
		game->exit = NULL;
	}
	if (game->blocks)
	{
		mlx_destroy_image(game->newmlx, game->blocks);
		game->blocks = NULL;
	}
	if (game->floor)
	{
		mlx_destroy_image(game->newmlx, game->floor);
		game->floor = NULL;
	}
}

int	exit_door(t_long *game)
{
	free_image(game);
	if (game->mywindow)
	{
		mlx_destroy_window(game->newmlx, game->mywindow);
		game->mywindow = NULL;
	}
	if (game->newmlx)
	{
		mlx_destroy_display(game->newmlx);
		free (game->newmlx);
		game->newmlx = NULL;
	}
	free_map(game);
	return (0);
}

static	void	create_window(t_long *game)
{
	int	wid;
	int	ht;

	game->newmlx = mlx_init();
	if (!(game->newmlx))
	{
		ft_printf("Failed to initialize MLX\n");
		exit_door(game);
	}
	wid = game->widthmp * 50;
	ht = game->heightmp * 50;
	game->mywindow = mlx_new_window(game->newmlx, wid, ht, "so_long");
	if (!(game->mywindow))
	{
		ft_printf("Failed to create window\n");
		exit_door(game);
	}
	create_images(game);
	put_images(game, 0, 0);
	mlx_key_hook(game->mywindow, set_controls, game);
	mlx_hook(game->mywindow, 17, 0, exit_button, game);
	mlx_loop(game->newmlx);
}

int	main(int argc, char **argv)
{
	t_long	game;
	int		para_len;
	int		createdmap;

	if (argc != 2)
	{
		ft_printf("Error: No map provided for the Game\n");
		return (0);
	}
	para_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][para_len - 4], ".ber", 4))
	{
		ft_printf("Error: Invalid map file provided.\n");
		return (0);
	}
	ft_memset(&game, 0, sizeof(t_long));
	createdmap = create_map(&game, argv);
	if (!createdmap)
		return (exit_door(&game));
	createdmap = map(&game, argv);
	if (!createdmap)
		return (exit_door(&game));
	create_window(&game);
	return (1);
}
