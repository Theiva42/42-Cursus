/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:55:55 by thkumara          #+#    #+#             */
/*   Updated: 2024/07/04 13:31:53 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	strjoin = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (strjoin == NULL)
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
		strjoin[j++] = s1[i++];
	i = 0;
	while (s2 != NULL && s2[i] != '\0')
		strjoin[j++] = s2[i++];
	strjoin[j] = '\0';
	return (strjoin);
}

char	*next_line(char	*buff)
{
	char	*line;
	size_t	index;
	size_t	j;

	line = NULL;
	index = 0;
	j = 0;
	while (buff[index] && buff[index] != '\n')
		index++;
	if (buff[index] == '\n')
		index++;
	line = (char *) malloc(index + 1 * sizeof(char));
	if (!line)
		return (NULL);
	while (j < index)
	{
		line[j] = buff[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_ptr_string(char *line)
{
	char	*ptr_string;
	size_t	i;
	size_t	j;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] != '\0' && line[i] == '\n')
		i++;
	if ((ft_strlen(line) - i) == 0)
		return (NULL);
	ptr_string = (char *) malloc(ft_strlen(line) - i + 1 * sizeof(char));
	if (!ptr_string)
		return (NULL);
	j = 0;
	while (line[i] != '\0')
		ptr_string[j++] = line[i++];
	ptr_string[j] = '\0';
	return (ptr_string);
}
