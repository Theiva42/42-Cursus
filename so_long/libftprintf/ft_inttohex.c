/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:09:34 by thkumara          #+#    #+#             */
/*   Updated: 2024/06/20 12:34:10 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_inttohex(unsigned int num, int x)
{
	char	hexnum[16];
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (num == 0)
		return (ft_putchar('0'));
	while (num != 0)
	{		
		if (x == 0)
			hexnum[i] = "0123456789abcdef"[num % 16];
		else if (x == 1)
			hexnum[i] = "0123456789ABCDEF"[num % 16];
		num /= 16;
		i++;
	}
	hexnum[i] = '\0';
	while (i > 0)
		count += ft_putchar(hexnum[--i]);
	return (count);
}
