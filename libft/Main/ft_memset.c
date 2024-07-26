/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:01:34 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/16 15:59:55 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<unistd.h>
#include<string.h>

void	*ft_memset (void *s, int c, size_t n)
{
	size_t	i;
	char *str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		*(str + i) = c;
		//*((unsigned char *)s + i) = c;
		i++;
	}
	return (str);
}

int	main (void)
{
        char    str[] = "false";
        char    str1[] = "12345";
	printf ("My Output:%p\n", ft_memset(str, '.', 3));
        printf ("My Output:%p\n", ft_memset(str1, '.', 3));
        printf ("Default Output:%p\n", memset(str, '.', 3));
        printf ("Default Output:%p\n", memset(str1, '.', 3));

}
