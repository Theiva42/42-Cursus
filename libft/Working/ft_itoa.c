/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:27:08 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/24 14:35:54 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	num_length;
	size_t	i;
	char	*string;

	num_length = ft_numlen(n);
	string = (char *) malloc ((num_length + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		i = num_length;
		string[0] = '-';
		string[1] = '2';
		n = 147483648;
		while (i > 2)
		{
			string[i - 1] = (n % 10) + 48;
			n /= 10;
			i--;
		}
	}
	else
	{
		i = num_length;
		if (n < 0)
		{
			string[0] = '-';
			n *= -1;
		}
		if (n == 0)
			string[0] = '0';
		while (num_length > 0 && n != 0)
		{
			string[num_length - 1] = (n % 10) + 48;
			n /= 10;
			num_length--;
		}
	}
	string[i + 1] = '\0';
	return (string);
}
