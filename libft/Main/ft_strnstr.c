/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:10:56 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/18 16:40:29 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<string.h>
#include<stdio.h>
#include<unistd.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)&big[i]);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

int     main(void)
{
        char    s1[] = "lorem ipsum dolor sit amet";
        char    s2[] = "dolor";

     // printf("%d Function\n", strstr(s1, s2, 0));
      printf("%s My Function\n", ft_strnstr(s1, s2, 0));
}
