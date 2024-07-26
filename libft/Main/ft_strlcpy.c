/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:27:20 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/17 13:20:50 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <unistd.h>

unsigned int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[count])
		count++;
	if (size < 1)
		return (count);
	else
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (count);
}

int main() {
    // Test cases
    char src1[] = "Hello, world!";
    char dst1[20];
    char dst2[10];
    char dst3[1];
    unsigned int length1, length2, length3;

    // Copying to a buffer large enough to hold the source
    length1 = ft_strlcpy(dst1, src1, sizeof(dst1));
    printf("Source: \"%s\"\n", src1);
    printf("Destination 1: \"%s\"\n", dst1);
    printf("Returned length: %u\n", length1);
    printf("Expected length: %zu\n\n", strlen(src1));

    // Copying to a smaller buffer
    length2 = ft_strlcpy(dst2, src1, sizeof(dst2));
    printf("Source: \"%s\"\n", src1);
    printf("Destination 2: \"%s\"\n", dst2);
    printf("Returned length: %u\n", length2);
    printf("Expected length: %zu\n\n", strlen(src1));

    // Copying to a buffer of size 1 (just enough for null terminator)
    length3 = ft_strlcpy(dst3, src1, sizeof(dst3));
    printf("Source: \"%s\"\n", src1);
    printf("Destination 3: \"%s\"\n", dst3);
    printf("Returned length: %u\n", length3);
    printf("Expected length: %zu\n\n", strlen(src1));

    return 0;
}
