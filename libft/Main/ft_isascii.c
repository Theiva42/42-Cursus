/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:48:54 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/15 14:51:34 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>
#include<ctype.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int     main(void)
{
        int    str = 'a';
        int    str1 = 'Z';

        printf ("My Output:%d\n", ft_isascii(str));
        printf ("My Output:%d\n", ft_isascii(str1));
        printf ("Default Output:%d\n", isascii(str));
        printf ("Default Output:%d\n", isascii(str1));
}