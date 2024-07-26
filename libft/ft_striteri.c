/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:38:10 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/28 15:44:20 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	if (s == NULL || f == NULL)
		return ;
	len = ft_strlen (s);
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
