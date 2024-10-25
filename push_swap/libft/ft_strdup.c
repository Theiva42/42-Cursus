/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:26:21 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/20 16:27:44 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*dup_s;

	dup_s = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
	if (dup_s == NULL)
		return (NULL);
	ft_strcpy(dup_s, (char *)s);
	return (dup_s);
}
