/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:27:41 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/28 16:32:43 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n * -1, fd);
	}
	else if (n < 10)
		ft_putchar_fd((char)(n + '0'), fd);
	else
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

int main() {
    // Test with various integers
    int integers[] = {123, -456, 0, -2147483648, 987654321};

    printf("Printing integers using ft_putnbr_fd:\n");
    for (long unsigned int i = 0; i < sizeof(integers) / sizeof(integers[0]); i++) {
        printf("Integer: %d\n", integers[i]);
        ft_putnbr_fd(integers[i], STDOUT_FILENO);
        ft_putchar_fd('\n', STDOUT_FILENO); // Print a newline after each integer
    }

    return 0;
}
