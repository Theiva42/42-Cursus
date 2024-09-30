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

static void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;
	char *str;

	i = 0;
	str = (char *)s;
	while(i < len)
	{
		*(str + i) = c;
		i++;
	}
	return (s);
}

int	exit_door(t_long *game)
{
	int	i;

	i = 0;
	if (game->mywindow)
		mlx_destroy_window(game->newmlx, game->mywindow);
	free(game->newmlx);
	while (i < game->heightmap - 1)
		free(game->map[i++]);
	free(game->map);
	exit(0);
}

int main(int argc, char **argv)
{
	t_long	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0 sizeof(t_long);
	create_map(&game, argv);
	check_map(&game);
	game.newmlx = mlx_init();
	game.mywindow = mlx_new_window(game.newmlx, (game.widthmap * 40), (game.heightmap * 40), "so_long Project");
	create_images(&game);
	put_images(&game);
	mlx_key_hook(game.mywindow, set_controls, &game);
	mlx_hook(game.mywindow, 17, 0, (void *)exit, 0);
	mlx_loop(game.newmlx);
}
