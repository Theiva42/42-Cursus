/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:35:44 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/15 16:59:15 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>
#include<ctype.h>

int     ft_isalnum (int c)
{
        if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
        	return (8);
        return (0);
}

int     main(void)
{
        int    str = 'a';
        int    str1 = '3';

        printf ("My Output:%d\n", ft_isalnum(str));
        printf ("My Output:%d\n", ft_isalnum(str1));
        printf ("Default Output:%d\n", isalnum(str));
        printf ("Default Output:%d\n", isalnum(str1));
}
