/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:39:11 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/21 17:16:50 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	strjoin = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (strjoin == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		strjoin[j] = s1[j];
		j++;
	}
	while (s2[i] != '\0')
	{
		strjoin[j + i] = s2[i];
		i++;
	}
	strjoin[j + i] = '\0';
	return (strjoin);
}

int main()
{
	const char *dest = "lorem ipsum";
	const char *src = "dolor sit amet";

	printf("String join output: %s\n", ft_strjoin(dest, src));
}
