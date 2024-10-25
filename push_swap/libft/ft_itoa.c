/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:27:08 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/28 14:46:36 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_convert(char *string, size_t num_length, int n)
{
	long			num;
	size_t			i;

	num = n;
	string[num_length] = '\0';
	if (num == 0)
	{
		string[0] = '0';
		return (string);
	}
	else if (num < 0)
	{
		string[0] = '-';
		num *= -1;
	}
	i = num_length - 1;
	while (num > 0)
	{
		string[i--] = (num % 10) + '0';
		num /= 10;
	}
	return (string);
}

char	*ft_itoa(int n)
{
	size_t	num_length;
	char	*new;
	char	*string;

	num_length = ft_numlen(n);
	string = (char *)malloc ((num_length + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	new = ft_convert(string, num_length, n);
	return (new);
}
