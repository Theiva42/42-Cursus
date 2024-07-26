/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:40:16 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/29 13:31:59 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<string.h>
#include<stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}


int main() {
    const char *str = "teste";
    int target_char = '\0';

    // Find the first occurrence of 'o' in str
    char *result = strchr(str, target_char);

    if (result != NULL) {
        printf("'%c' found at position %ld\n", target_char, result - str);
        printf("Rest of the string after '%c': %s\n", target_char, result);
    } else {
        printf("'%c' not found in the string.\n", target_char);
    }

    return 0;
}
