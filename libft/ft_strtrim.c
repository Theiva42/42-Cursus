/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:32:08 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/23 12:55:51 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	newstr = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	newstr = (char *)malloc(sizeof(char) * (j - i + 1));
	if (newstr == NULL)
		return (NULL);
	if (newstr != NULL)
		ft_strlcpy(newstr, &s1[i], j - i + 1);
	return (newstr);
}
