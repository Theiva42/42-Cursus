/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:20:20 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/15 16:26:22 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>
#include<ctype.h>

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (2048);
	return (0);
}
			
int     main(void)
{
        int    str = '9';
        int    str1 = '1';

        printf ("My Output:%d\n", ft_isdigit(str));
        printf ("My Output:%d\n", ft_isdigit(str1));
        printf ("Default Output:%d\n", isdigit(str));
        printf ("Default Output:%d\n", isdigit(str1));
}
