/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:01:34 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/16 18:14:33 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<unistd.h>
#include<string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}

int main()
{
    char source[] = "Hello, World!";
    char destination[20];

    // Copy data using ft_memcpy
    ft_memcpy(destination, source, 5);

    // Print the copied string
    printf("Copied string: %s\n", destination);

    return 0;
}
