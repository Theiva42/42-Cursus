/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:36:59 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/21 17:12:49 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	substring = (char *)malloc(len + 1 * sizeof(char));
	if (substring == NULL)
	       //	|| start < 0 || start > ft_strlen(s) || len <= 0)
		return (NULL);
	//if (start < 0 || start > ft_strlen(s) || len <= 0 || len + start > ft_strlen(s))
	while (s[i])
	{
		if (i == start)
		{
			j = 0;
			while (j < len)
			{
				substring[j] = s[i + j];
				j++;
			}
		}
		i++;
	}
	substring[j] = '\0';
	return (substring);
}

int	main(void)
{
	char	*s = "Believe it, Do it!";
	unsigned int	start;
	size_t	len;

	start = -5;
	len = -5;
	printf("Substring created: %s\n", ft_substr(s, start, len));
}
