/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:30:42 by thkumara          #+#    #+#             */
/*   Updated: 2024/11/03 16:30:52 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	ft_handle_char(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	return (write(1, &c, 1));
}

int	ft_handle_int(va_list ap)
{
	long long	n;
	int			neg;

	n = va_arg(ap, int);
	neg = 0;
	if (n < 0)
	{
		n *= -1;
		neg++;
		write(1, "-", 1);
	}
	return (ft_putnbr_base(n, "0123456789") + neg);
}

int	ft_handle_hexlower(va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	return (ft_putnbr_base(n, "0123456789abcdef"));
}

int	ft_handle_hexupper(va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	return (ft_putnbr_base(n, "0123456789ABCDEF"));
}

int	ft_handle_percent(void)
{
	ft_putchar('%');
	return (1);
}
