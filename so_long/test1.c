/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:20:53 by thkumara          #+#    #+#             */
/*   Updated: 2024/09/12 17:54:37 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minilibx-linux/mlx.h"
#include<stdio.h>
#include<stdlib.h>

int close_window(void *param)
{
    (void)param;
    exit(0);
}

int	main(void)
{
	void	*new_connection;
	void	*mlx_window;
	void	*img;
	int	width = 50;
	int height = 50;

	new_connection = mlx_init();
    if (new_connection == NULL)
    {
        printf("Error inializing MiniLibx\n");
        return(1);
    }
	mlx_window = mlx_new_window(new_connection, 800, 800, "My 1st Window");
    if (mlx_window == NULL)
    {
        printf("Error creating window\n");
        return(1);
    }
	for (int i = 0; i < 20; i++)
	{
		mlx_pixel_put(new_connection, mlx_window, i, 1, 0xff000);
		mlx_pixel_put(new_connection, mlx_window, i, 20, 0xff000);
		mlx_pixel_put(new_connection, mlx_window, 1, i, 0xff000);
		mlx_pixel_put(new_connection, mlx_window, 20, i, 0xff000);
		mlx_pixel_put(new_connection, mlx_window, 10, 20 + i, 0xff000);
		mlx_pixel_put(new_connection, mlx_window, 10 + i, 25 + i, 0xff000);
		mlx_pixel_put(new_connection, mlx_window, 10 + i, 40, 0xff000);
    }
    img = mlx_xpm_file_to_image(new_connection, "character.xpm", &width,&height);
    if (img == NULL)
    {
        printf("Error loading the character\n");
        return(1);
    }
    mlx_put_image_to_window(new_connection, mlx_window, img, 100, 100);
    void *img1 = mlx_xpm_file_to_image(new_connection, "mickey.xpm", &width,&height);
    if (img1 == NULL)
    {
        printf("Error loading the character\n");
        return(1);
    }
    mlx_put_image_to_window(new_connection, mlx_window, img1, 300, 100);
    void *img2 = mlx_xpm_file_to_image(new_connection, "exit-door.xpm", &width,&height);
    if (img2 == NULL)
    {
        printf("Error loading the door\n");
        return(1);
    }
    mlx_put_image_to_window(new_connection, mlx_window, img2, 400, 400);
    void *wall = mlx_xpm_file_to_image(new_connection, "wall.xpm", &width,&height);
    if (wall == NULL)
    {
        printf("Error loading the door\n");
        return(1);
    }
   // for (int i = 0; i < 400; i++)
	//{
        
        mlx_put_image_to_window(new_connection, mlx_window, wall, 100, 0);
   // }
   void *collect1 = mlx_xpm_file_to_image(new_connection, "collectable1.xpm", &width, &height);
    if (collect1 == NULL)
    {
        printf("Error loading the door\n");
        return(1);
    }
   mlx_put_image_to_window(new_connection, mlx_window, collect1, 250, 0);
    mlx_hook(mlx_window, 17, 0, close_window, NULL);
	mlx_loop(new_connection);
    return(0);
}
