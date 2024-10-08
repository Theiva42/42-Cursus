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

static char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)&big[i]);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

static void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char *str;

	str = (unsigned char *)s;
	while(len--)
		*str++ = (unsigned char)c;
	return (s);
}

int	exit_door(t_long *game)
{
	int	i;

	i = 0;
	if (game->mywindow)
	{
		mlx_destroy_window(game->newmlx, game->mywindow);
		game->mywindow = NULL;
	}
	 if (game->newmlx)
    {
        free(game->newmlx);
        game->newmlx = NULL;  // Set to NULL to avoid dangling pointer
    }
	if (game->map)
    {
        while (i < game->heightmap - 1)
        {
            if (game->map[i])   // Check if the row exists before freeing
            {
                free(game->map[i]);
                game->map[i] = NULL;  // Set to NULL to avoid dangling pointer
            }
            i++;
        }
	free(game->map);
	game->map = NULL;
	}
	return(0);
}

int main(int argc, char **argv)
{
	t_long	game;

	// char *argv[] ={"1111111111111\n11111P11111C1\n1000001000101\n1011101000C01\n1C10000001101\n1000111100001\n1010111100111\n1010011C00001\n10C1011111001\n11110000C10E1\n1111111111111"};
	if (argc != 2)
	{
		printf("Error: No map provided for the Game\n");
		return (0);
	}
	int para_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][para_len - 4],".ber", 4))
	{
    	printf("Error: Invalid map file provided.\n");
    	return (1);
	}
	ft_memset(&game, 0, sizeof(t_long));
	int map = create_map(&game, argv);
	if (!map)
		return (1);
	//printf("Finished create map\n");
	check_map(&game);
	//printf("Finished check map\n");
	game.newmlx = mlx_init();
	if (!(game.newmlx))
	{
    	printf("Failed to initialize MLX\n");
    	return (1);
	}
	game.mywindow = mlx_new_window(game.newmlx, (game.widthmap * 50), (game.heightmap * 50), "so_long Project");
	if (!(game.mywindow))
	{
    	printf("Failed to create window\n");
    	return (1);
	}
	create_images(&game);
	put_images(&game);
	mlx_key_hook(game.mywindow, set_controls, &game);
	//mlx_hook(game.mywindow, 17, 0, exit_door, &game);
	mlx_hook(game.mywindow, 17, 0, (void *)exit, 0);
	//mlx_hook(game.mywindow, 2, 1L<<0, set_controls, NULL);
	mlx_loop(game.newmlx);
}
