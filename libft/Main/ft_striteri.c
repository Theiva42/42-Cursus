/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:38:10 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/28 15:44:20 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	if (s == NULL || f == NULL)
		return ;
	len = ft_strlen (s);
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}

void to_uppercase(unsigned int index, char *c) {
    (void)index;  // Unused parameter
    if (*c >= 'a' && *c <= 'z') {
        *c = *c - ('a' - 'A');
    }
}

int main() {
    char str[] = "hello world";
    ft_striteri(str, to_uppercase);
    printf("Output string: %s\n", str);  // Output should be: "HELLO WORLD"
    return 0;
}
