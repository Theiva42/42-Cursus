/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:48:32 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/28 15:52:17 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdio.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd (s[i], fd);
		i++;
	}
}

int main() {
    // Test with various strings
    char *strings[] = {"Hello, World!", "Testing", "12345"};

    printf("Printing strings using ft_putstr_fd:\n");
    for (size_t i = 0; i < sizeof(strings) / sizeof(strings[0]); i++) {
        printf("String: %s\n", strings[i]);
        ft_putstr_fd(strings[i], STDOUT_FILENO);
        ft_putchar_fd('\n', STDOUT_FILENO); // Print a newline after each string
    }

    return 0;
}
