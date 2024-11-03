/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:29:52 by thkumara          #+#    #+#             */
/*   Updated: 2024/11/03 16:30:19 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putnbr_base(unsigned long long nb, const char *base)
{
	unsigned long long	len;
	int					count;

	count = 0;
	len = ft_strlen(base);
	if (nb >= len)
		count += ft_putnbr_base(nb / len, base);
	count += ft_putchar(base[nb % len]);
	return (count);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_specifier(char c, va_list ap)
{
	if (c == 'c')
		return (ft_handle_char(ap));
	if (c == 's')
		return (ft_handle_string(ap));
	if (c == 'i' || c == 'd')
		return (ft_handle_int(ap));
	if (c == 'u')
		return (ft_handle_unsigned(ap));
	if (c == 'p')
		return (ft_handle_pointer(ap));
	if (c == 'x')
		return (ft_handle_hexlower(ap));
	if (c == 'X')
		return (ft_handle_hexupper(ap));
	else if (c == '%')
		return (ft_handle_percent());
	return (write(1, &c, 1));
}

static int	process_format(const char **format, va_list ap)
{
	int	ret;

	if (**format == '%' && !*(*format + 1))
		return (0);
	else if (**format == '%')
	{
		(*format)++;
		ret = ft_specifier(**format, ap);
		if (ret == -1)
			return (-1);
		return (ret);
	}
	ret = write(1, *format, 1);
	if (ret == -1)
		return (-1);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		ret;

	if (!format)
		return (0);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		ret = process_format(&format, ap);
		if (ret == -1)
		{
			va_end(ap);
			return (-1);
		}
		count += ret;
		format++;
	}
	va_end(ap);
	return (count);
}
