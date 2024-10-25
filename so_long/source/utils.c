/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:06:47 by thkumara          #+#    #+#             */
/*   Updated: 2024/10/18 13:07:19 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (len--)
		*str++ = (unsigned char)c;
	return (s);
}

int	exit_button(t_long *game)
{
	exit_door(game);
	exit(EXIT_SUCCESS);
	return (0);
}

int	map(t_long *game, char **argv)
{
	int	map;
	int	i;

	i = 0;
	create_mapcpy(game, argv);
	map = check_map(game);
	if (!map)
		return (exit_door(game));
	else
	{
		while (i < game->heightmp)
		{
			if (!valid_char(game->map[i], game))
			{
				ft_printf("Error: Invalid character in the map provided.\n");
				return (exit_door(game));
			}
			i++;
		}
	}
	return (1);
}
