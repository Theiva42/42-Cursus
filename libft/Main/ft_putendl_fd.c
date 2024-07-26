/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:52:53 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/28 15:58:56 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdio.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (*s || fd)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int main() {
    // Test with various strings
    char *strings[] = {"Hello, World!", "Testing", "", "12345"};
    size_t	i;

	i = 0;
    printf("Printing strings using ft_putendl_fd:\n");
    while (i < ft_strlen(*strings)) {
        printf("String: %s\n", strings[i]);
        ft_putendl_fd(strings[i], STDOUT_FILENO);
        i++;
    }

    return 0;
}
