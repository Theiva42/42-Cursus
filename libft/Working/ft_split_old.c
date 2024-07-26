/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:56:36 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/23 18:32:47 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	ele;
	char	**newstrs;

	i = 0;
	k = 0;
	ele = 0;
	while (s[i] == c)
		i++;
	size_t	num_substr = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			num_substr++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
        	{
           		while (s[i] == c)
                	i++;
        	}
	}
	newstrs = (char **)malloc((i + 1) * sizeof(char));
	if (newstrs == NULL)
		return (NULL);

	newstrs[k] = (char *)malloc((i + 1) * sizeof(char));
	if (newstrs[k] == NULL)
	{
		while (k > 0)
			free (newstrs[--k]);
		free (newstrs);
		return (NULL);
	}
	while (k < i)
	{
		newstrs[k][ele] = s[k];
		ele++;
		k++;
	}
	printf ("Count:%zu",k);
	newstrs[k][ele] = '\0';
	return (newstrs);
}       
