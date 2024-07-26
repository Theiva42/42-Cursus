/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:32:20 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/30 18:04:18 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**free_mem(char **s, size_t i)
{
	while (s[i] != NULL && i >= 0)
	{
		free(s[i]);
		s[i] = NULL;
		i--;
	}
	free (s)
	s = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**newstr;

	if (!s)
		return (NULL);
	len = word_count(s, c);
	newstr = (char **)malloc((len + 1) * sizeof(char *));
	if (newstr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		len = 0;
		while (s[i + len] != '\0' && s[i + len] != c)
			len++;
		newstr[i++] = ft_substr(s, 0, len);
		if (i < word_count(s, c) && !(newstr))
			return (free_mem(newstr, i));
		i += len;
	}
	newstr[i] = 0;
	return (newstr);
}
