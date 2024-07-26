/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:05:38 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/15 15:09:17 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<ctype.h>
#include<stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	return (0);
}

int     main(void)
{
        int    str = 'z';
        int    str1 = 'A';

        printf ("My Output:%d\n", ft_isalpha(str));
        printf ("My Output:%d\n", ft_isalpha(str1));
        printf ("Default Output:%d\n", isalpha(str));
        printf ("Default Output:%d\n", isalpha(str1));
}
