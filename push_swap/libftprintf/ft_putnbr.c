/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:32:33 by thkumara          #+#    #+#             */
/*   Updated: 2024/06/20 12:32:48 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int		count;
	char	digits[12];
	int		i;

	count = 0;
	i = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb *= -1;
	}
	if (nb == 0)
		count += ft_putchar('0');
	while (nb > 0)
	{
		digits[i++] = nb % 10 + 48;
		nb = nb / 10;
	}
	while (i > 0)
		count += ft_putchar(digits[--i]);
	return (count);
}
