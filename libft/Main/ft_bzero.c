/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:01:34 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/16 17:09:40 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<unistd.h>
#include<string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)s + i) = 0;
		i++;
	}
}

int main()
{
    char buffer[10];

    // Initialize buffer with non-zero values
    for (int i = 0; i < 10; i++) {
        buffer[i] = i + 1;
    }

    // Print buffer before ft_bzero
    printf("Buffer before ft_bzero:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    // Zero out the buffer using ft_bzero
    ft_bzero(buffer, 5);

    // Print buffer after ft_bzero
    printf("Buffer after ft_bzero:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    return 0;
}
