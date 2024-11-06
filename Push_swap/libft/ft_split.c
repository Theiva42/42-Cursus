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

static size_t	word_count(char const *s, char c)
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
	while (i > 0)
	{
		free(s[i - 1]);
		i--;
	}
	free (s);
	return (NULL);
}

static char	**create_word(char const *s, char c, char **newstr)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		newstr[j] = ft_substr(s, start, i - start);
		if (!(newstr)[j])
			return (free_mem(newstr, j));
		j++;
	}
	newstr[j] = NULL;
	return (newstr);
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	char	**newstr;

	if (!s)
		return (NULL);
	len = word_count(s, c);
	newstr = (char **)malloc((len + 1) * sizeof(char *));
	if (newstr == NULL)
		return (NULL);
	newstr = create_word (s, c, newstr);
	return (newstr);
}
