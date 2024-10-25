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
# include <fcntl.h>
# include "headers/get_next_line.h"
# include "headers/ft_printf.h"
# include "headers/mlx.h"

typedef struct t_start
{
	int			fd;
	int			heightmp;
	int			widthmp;
	int			heightcpy;
	int			widthcpy;
	int			pcount;
	int			collcount;
	int			exitcount;
	int			x_axis;
	int			y_axis;
	int			counter;
	int			collectables;
	int			c_flag;
	int			e_flag;

	char		**map;
	char		**mapcpy;

	void		*floor;
	void		*blocks;
	void		*player;
	void		*exit;
	void		*collect;
	void		*newmlx;
	void		*mywindow;

}	t_long;

void	*ft_memset(void *s, int c, size_t len);
void	put_images(t_long *game, int height, int width);
void	create_images(t_long *game);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		exit_door(t_long *game);
int		create_map(t_long *game, char **argv);
int		create_mapcpy(t_long *game, char **argv);
int		set_controls(int key, t_long *game);
int		check_map(t_long *game);
int		check_map_shape(t_long *game);
int		check_chars(t_long *game);
int		right_move(t_long *game, int i, int j);
int		valid_char(char *str, t_long *game);
int		map(t_long *game, char **argv);
int		exit_button(t_long *game);

#endif
