/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:43:58 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/21 16:46:21 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	strjoin = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (strjoin == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		strjoin[j] = s1[j];
		j++;
	}
	while (s2[i] != '\0')
	{
		strjoin[j + i] = s2[i];
		i++;
	}
	strjoin[j + i] = '\0';
	return (strjoin);
}
