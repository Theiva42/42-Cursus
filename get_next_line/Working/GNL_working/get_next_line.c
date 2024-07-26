/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:29:57 by thkumara          #+#    #+#             */
/*   Updated: 2024/07/04 13:40:21 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_ptr;
	size_t			index;

	line = NULL;
	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
	{
		 if (line)
		 	free (line);
		return (NULL);
	}
		line = get_buff(fd);
		if (line_ptr)
			line = ft_strjoin(line_ptr, line);
		if (line)
		{
			line_ptr = get_ptr_string(line);
			line = next_line(line);
		}
	return (line);
}

int	main(void)
{
	int fd;
	char *str;

	fd = open ("test1", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf ("Get Next line: %s", str);
		free(str);
		str = NULL;
	}
	close(fd);
	return (0);
}