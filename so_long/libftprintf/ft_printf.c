/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:39:31 by thkumara          #+#    #+#             */
/*   Updated: 2024/06/20 14:02:28 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

static int	ft_formatcheck(char fs, va_list new)
{
	if (fs == '%')
		return (ft_putchar('%'));
	else if (fs == 'c')
		return (ft_putchar(va_arg(new, int)));
	else if (fs == 's')
		return (ft_putstr(va_arg(new, char *)));
	else if (fs == 'd' || fs == 'i')
		return (ft_putnbr(va_arg(new, int)));
	else if (fs == 'u')
		return (ft_putunsigned(va_arg(new, unsigned int)));
	else if (fs == 'p')
		return (ft_putptr(va_arg(new, unsigned long)));
	else if (fs == 'x')
		return (ft_inttohex(va_arg(new, unsigned int), 0));
	else if (fs == 'X')
		return (ft_inttohex(va_arg(new, unsigned int), 1));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	new;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(new, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			count += ft_formatcheck(format[i + 1], new);
			i++;
		}
		else
			count += ft_putchar((char)format[i]);
		i++;
	}
	va_end(new);
	return (count);
}
