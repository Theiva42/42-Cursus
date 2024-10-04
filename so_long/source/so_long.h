/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:20:10 by thkumara          #+#    #+#             */
/*   Updated: 2024/09/27 12:25:47 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "getnextline/get_next_line.h"
# include "minilibx-linux/mlx.h"

typedef struct t_start
{
	int			fd;
	int			heightmap;
	int			widthmap;
	int			playercount;
	int			columncount;
	int			exitcount;
	int			x_axis;
	int			y_axis;
	int			counter;
	int			collectables;

	char	**map;

	void	*floor;
	void	*blocks;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*newmlx;
	void	*mywindow;

}	t_long;

int			exit_door(t_long *game);
int			create_map(t_long *game, char **argv);
int			set_controls(int key, t_long *game);
void	put_images(t_long *game);
void	create_images(t_long *game);
void	check_map(t_long *game);

#endif
