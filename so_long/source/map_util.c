/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:25:25 by thkumara          #+#    #+#             */
/*   Updated: 2024/10/17 14:25:47 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	valid_char(char *str, t_long *game)
{
	int	j;

	j = 0;
	while (j < game->widthmp)
	{
		if (str[j] && str[j] != '1' && str[j] != '0' && str[j] != 'E')
		{
			if (str[j] != 'P' && str[j] != 'C' && str[j] != '\n')
				return (0);
		}
		j++;
	}
	return (1);
}

int	check_map_shape(t_long *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->heightmp)
	{
		if (game->map[j] == NULL)
			return (0);
		i = 0;
		while (game->map[j][i] && game->map[j][i] != '\n')
			i++;
		if (i != game->widthmp)
			return (0);
		j++;
	}
	return (1);
}

int	check_chars(t_long *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmp - 1)
	{
		width = 0;
		while (width <= game->widthmp)
		{
			if (game->map[height][width] == 'P')
				game->pcount++;
			if (game->map[height][width] == 'C')
				game->collcount++;
			if (game->map[height][width] == 'E')
				game->exitcount++;
			width++;
		}
		height++;
	}
	if (!(game->pcount == 1 && game->collcount >= 1 && game->exitcount == 1))
	{
		ft_printf("\nError in Player or Collectables or Exit\n");
		return (exit_door(game));
	}
	return (1);
}

int	right_move(t_long *game, int i, int j)
{
	if (j < 0 || j >= game->heightmp || i < 0 || i >= game->widthmp)
		return (-1);
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (-1);
		ft_printf("\nYou Have Won, Congrats!\n");
		return (exit_door(game));
	}
	if (game->map[j][i] == 'C')
		game->collectables--;
	if (game->map[j][i] == '0' || game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	else
		return (-1);
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
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
