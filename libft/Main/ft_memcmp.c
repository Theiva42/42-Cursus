/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:28:52 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/18 14:59:43 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<string.h>
#include<stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1 || s2) && i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

int main()
{
    const char *str1 = "t\200";
    const char *str2 = "t\0";

    int result = ft_memcmp(str1, str2, 2);
    int result1 = memcmp(str1, str2, 2);

    printf ("My Result:%d\n",result);
    printf ("Default Result:%d\n",result1);

    if (result == 0) 
        printf("1. The first 7 characters of the strings are equal.\n");
    else if (result < 0) 
        printf("1. The first 7 characters of str1 are less than str2.\n");
    else 
        printf("1. The first 7 characters of str1 are greater than str2.\n");
    if (result1 == 0)
        printf("2. The first 7 characters of the strings are equal.\n");
    else if (result1 < 0)
        printf("2. The first 7 characters of str1 are less than str2.\n");
    else
        printf("2. The first 7 characters of str1 are greater than str2.\n");

    return 0;
}
