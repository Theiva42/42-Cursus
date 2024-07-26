/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:19:54 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/23 12:36:32 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

unsigned int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[count])
		count++;
	if (size < 1)
		return (count);
	else
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	newstr = 0;
	if (s1 && set)
	{
		while (s1[i] != '\0' && ft_strchr(set, s1[i]))
			i++;
		while (j > 0 && ft_strchr(set, s1[j - 1]))
			j--;
		newstr = (char *)malloc(sizeof(char) * (j - i + 1));
		if (newstr == NULL)
			return (NULL);
		if (newstr)
			ft_strlcpy(newstr, &s1[i], j - i + 1);
	}		
	return (newstr);
}

int	main(void)
{
	char const	*s1;
	char const	*set;

	s1 = " eello, you there ";
	set = "";


	printf ("String before function: %s", s1);
	printf ("String after function: %s", ft_strtrim(s1, set));
}
