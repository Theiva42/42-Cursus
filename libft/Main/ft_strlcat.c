/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:23:48 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/29 12:19:05 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>
#include<string.h>

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
        size_t  i;
        size_t  dst_len;
	size_t	src_len;

        i = 0;
        dst_len = 0;
	src_len = 0;
        while (dst[dst_len] && dst_len < size)
               dst_len++;
	while (src[src_len] != '\0')
		src_len++;
        while (src[i] &&  (dst_len + i + 1) < size)
        {
               dst[dst_len + i] = src[i];
               i++;
        } 
        if (dst_len < size)
                dst[dst_len + i] = '\0';
        return (dst_len + src_len);
}


int main() {
    // Test cases
    char src1[] = "Hello, world!";
    char dst1[20] = "Hello";
    char dst2[10] = "world";
    char dst3[1] = "!";
    unsigned int length1, length2, length3;

    // Copying to a buffer large enough to hold the source
    length1 = ft_strlcat(dst1, src1, 5);
    printf("Source: \"%s\"\n", src1);
    printf("Destination 1: \"%s\"\n", dst1);
    printf("Returned length: %u\n", length1);
    //printf("Expected length: %lu\n", strlen(dst1) + strlen(src1));

    // Copying to a smaller buffer
    length2 = ft_strlcat(dst2, src1, 5);
    printf("Source: \"%s\"\n", src1);
    printf("Destination 2: \"%s\"\n", dst2);
    printf("Returned length: %u\n", length2);
    //printf("Expected length: %lu\n", strlen(dst2) + strlen(src1));

    // Copying to a buffer of size 1 (just enough for null terminator)
    length3 = ft_strlcat(dst3, src1, 1);
    printf("Source: \"%s\"\n", src1);
    printf("Destination 3: \"%s\"\n", dst3);
    printf("Returned length: %u\n", length3);
    //printf("Expected length: %lu\n", strlen(dst3) + strlen(src1));

    return 0;
}
