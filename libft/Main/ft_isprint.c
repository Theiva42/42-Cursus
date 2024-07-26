/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:48:54 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/15 17:14:52 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>
#include<ctype.h>

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (16384);
	return (0);
}

int     main(void)
{
        int    str = 'f';
        int    str1 = 'Z';

        printf ("My Output:%d\n", ft_isprint(str));
        printf ("My Output:%d\n", ft_isprint(str1));
        printf ("Default Output:%d\n", isprint(str));
        printf ("Default Output:%d\n", isprint(str1));
}
