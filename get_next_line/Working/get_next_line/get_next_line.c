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

static char	*get_buff(int fd, char *line_ptr)
{
	ssize_t	readresult;
	char	*buff;

	readresult = 1;
	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (readresult > 0)
	{
		readresult = read (fd, buff, BUFFER_SIZE);
		if (readresult == -1)
			return (free (buff), NULL);
		buff[readresult] = '\0';
		if (readresult == 0)
			break ;
		line_ptr = ft_strjoin(line_ptr, buff);
		if (line_ptr == NULL)
			return (free (buff), NULL);
		if (ft_strchr(line_ptr, '\n'))
			break ;
	}
	free (buff);
	return (line_ptr);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*newline;
	static char	*line_ptr;

	line = NULL;
	newline = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	line = get_buff(fd, line_ptr);
	if (line == NULL)
	{
		free (line_ptr);
		line_ptr = NULL;
		return (free (line), NULL);
	}
	line_ptr = get_ptr_string(line);
	newline = next_line(line);
	if (!newline)
	{
		free(line_ptr);
		line_ptr = NULL;
	}
	return (newline);
}
int	main(void)
{
 	int fd;

  	fd = open("variable_nls.txt", O_RDONLY);
  	for (char *line = get_next_line(fd); line; line = get_next_line(fd))
 	{
 		printf("line: %s", line);
 		free(line);
 	}
 	get_next_line(fd);
 	return (0);
  }
