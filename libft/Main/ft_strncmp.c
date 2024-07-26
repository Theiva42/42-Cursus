/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:56:04 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/17 18:14:19 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<string.h>
#include<unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((*s1 || *s2) && n > 0)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		n--;
	}
	return (0);	
}

int main()
{
    const char *str1 = "abcdefgh";
    const char *str2 = "abcdwxyz";

    int result = ft_strncmp(str1, str2, 4);
    int result1 = strncmp(str1, str2, 4);

    printf ("My Result:%d\n",result);
    printf ("Default Result:%d\n",result1);

    if (result == 0) 
        printf("The first 7 characters of the strings are equal.\n");
    else if (result < 0) 
        printf("The first 7 characters of str1 are less than str2.\n");
    else 
        printf("The first 7 characters of str1 are greater than str2.\n");
    if (result1 == 0)
        printf("The first 7 characters of the strings are equal.\n");
    else if (result1 < 0)
        printf("The first 7 characters of str1 are less than str2.\n");
    else
        printf("The first 7 characters of str1 are greater than str2.\n");

    return 0;
}
