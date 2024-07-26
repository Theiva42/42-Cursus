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

static char	*get_buff(int fd)
{
	ssize_t	readresult;
	char	*buff;
	char	*temp;

	readresult = 1;
	temp = NULL;
	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (readresult > 0)
	{
		readresult = read (fd, buff, BUFFER_SIZE);
		if (readresult == -1 || readresult == 0)
		{
			free (buff);
			return (NULL);
		}	
		buff[readresult] = '\0';
		temp = ft_strjoin(temp, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free (buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_ptr;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
	{
		if (line)
		{
			free (line);
			return (NULL);
		}
	}
	line = get_buff(fd);
	if (line_ptr)
		line = ft_strjoin(line_ptr, line);
	if (!line)
		return (NULL);
	line_ptr = get_ptr_string(line);
	line = next_line(line);
	return (line);
}

int	main(void)
{
	int fd;
	// char *str;

	// fd = open ("test1", O_RDONLY);
	// while ((str = get_next_line(fd)) != NULL)
	// {
	// 	printf ("Get Next line: %s", str);
	// 	free(str);
	// 	str = NULL;
	// }
	// close(fd);
	
	
	fd = open("1char", O_RDONLY);
	
	char *temp;
	do {
		temp = get_next_line(fd);
		printf ("Get Next line: %s", temp);
		free(temp);
	} while (temp != NULL);
		
	free (temp);
	return (0);
}
