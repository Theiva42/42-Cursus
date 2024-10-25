/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:46:50 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/30 14:27:21 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*subs(unsigned int start, char *s, size_t len, char *substring)
{	
	size_t	i;

	i = 0;
	while (i < len && s[start + i])
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substring = (char *)malloc(1);
		if (substring == NULL)
			return (NULL);
		substring[0] = '\0';
		return (substring);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	substring = subs(start, (char *)s, len, substring);
	return (substring);
}
