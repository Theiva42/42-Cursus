/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:53:32 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/20 16:26:11 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_strdup(const char *s)
{
	char *dup_s;
	dup_s = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));

	if (dup_s == NULL)
		return (NULL);
	ft_strcpy(dup_s, (char *)s);
	return (dup_s);
}

int main() {
    const char *s = "ALL IS GOOD";
    char *duplicate;

    duplicate = ft_strdup(s);
    //duplicate = strdup(s);
    if (duplicate == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Original: %s\n", s);
    printf("Duplicate: %s\n", duplicate);

    // Free the allocated memory for the duplicate string
    free(duplicate);

    return 0;
}
