/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:48:54 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/16 13:38:26 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>
#include<string.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int     main(void)
{
        char    str[] = "false";
        char    str1[] = "1234566";

        printf ("My Output:%lu\n", ft_strlen(str));
        printf ("My Output:%lu\n", ft_strlen(str1));
        printf ("Default Output:%lu\n", strlen(str));
        printf ("Default Output:%lu\n", strlen(str1));
}
