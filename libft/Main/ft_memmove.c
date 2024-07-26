/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:01:34 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/29 11:44:18 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

void    *ft_memmove(void *dest, const void *src, size_t n)
{
        size_t  i;

        i = 0;
        if (src < dest)
        {
                i = n;
                while (i > 0)
                {
                        i--;
                        ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
                }
        }
        else
        {
		i = 0;
		while (i < n)
                {
                        ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
                        i++;
                }
	}
	return (dest);
}

int main()
{
    char source[] = "Hello, World!";
    char destination[20];

    // Copy data using ft_memcpy
    ft_memmove(destination, source, 15);

    // Print the copied string
    printf("Copied string: %s\n", destination);

    return 0;
}
