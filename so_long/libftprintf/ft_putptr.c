/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:35:32 by thkumara          #+#    #+#             */
/*   Updated: 2024/06/20 12:33:19 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_intthex(unsigned long num)
{
	char	hexnum[16];
	int		count;
	int		i;

	i = 0;
	count = 2;
	while (num != 0)
	{	
		hexnum[i] = "0123456789abcdef"[num % 16];
		num /= 16;
		i++;
	}
	hexnum[i] = '\0';
	ft_putstr("0x");
	while (i > 0)
		count += ft_putchar(hexnum[--i]);
	return (count);
}

int	ft_putptr(unsigned long num)
{
	if (num == 0)
		return (ft_putstr("(nil)"));
	else
		return (ft_intthex(num));
}
