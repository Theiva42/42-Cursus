/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:00:14 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/28 15:21:55 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

static size_t	ft_numlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_convert(char *string, size_t num_length, int n)
{
	size_t	i;
	long		num;

	i = num_length - 1;
	num = n;
	if (num < 0)
	{
		string[0] = '-';
		num *= -1;
		i++;
	}
	string[num_length] = '\0';
	if (num == 0)
	{
		string[0] = '0';
	}
	else
	{
		while (num > 0)
		{
			string[i--] = (num % 10) + '0';
			num /= 10;
		}
	}
	return (string);
}

char	*ft_itoa(int n)
{
	size_t	num_length;
	char	*new;
	char	*string;

	num_length = ft_numlen(n);
	string = malloc ((num_length + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	new = ft_convert(string, num_length, n);
	return (new);
}

int main(void)
{
    int test_num = -2147483647;
    char *result = ft_itoa(test_num);
    if (result != NULL)
    {
        printf("Int to String: %s\n", result);
        free(result);
    }
    return 0;
}
