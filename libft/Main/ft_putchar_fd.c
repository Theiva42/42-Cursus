/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:45:03 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/28 15:48:11 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

int main() {
    // Test with various integers
    int integers[] = {123, -456, 0, -2147483648, 987654321};
    int	i = 0;

    printf("Printing integers using ft_putnbr_fd:\n");
    while (i < *integers) {
        printf("Integer: %d\n", integers[i]);
        ft_putnbr_fd(integers[i], STDOUT_FILENO);
        ft_putchar_fd('\n', STDOUT_FILENO); // Print a newline after each integer
        i++;
    }

    return 0;
    }
