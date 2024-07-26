/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:39:31 by thkumara          #+#    #+#             */
/*   Updated: 2024/06/11 16:19:15 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write (1, &c, 1);
}

static void	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		ft_putchar(str[len]);
		len++;
	}
}

static void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		ft_putnbr(nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

/*int ft_formatcheck(char fs,va_list *new, int len, int i)
{
	 if (fs == '%')
		 ft_putchar('%');
	 if (fs == 'c')
		 ft_putchar(va_arg(new, int));
	 else if (fs == 's')
		 ft_putstr(va_arg(new, char *));
	 else if (fs == 'p')
		 ft_putchar(va_arg(new, int));
	 else if (fs == 'd')
		 ft_putnbr(va_arg(new, int));
	 else if (fs == 'i')
		 ft_putnbr(va_arg(new, int));
	 else if (fs == 'u')
		 ft_putnbr(va_arg(new, unsigned int));
	 else if (fs == 'x' || fs == 'X')
		 ft_putnbr(va_arg(new, int));
	return(len);
}*/

int	ft_printf(const char *format, ...)
{
	va_list	new;
	int		i;
	int		count;

	i = 0;
	count = -1;
	va_start(new, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			//ft_formatcheck(format[i], &new, count, i);
			if (format[i] == '%')
				ft_putchar('%');
			if (format[i] == 'c' || format[i] == 'p') 
				ft_putchar(va_arg(new, int));
			else if (format[i] == 's')
				ft_putstr(va_arg(new, char *));
			else if (format[i] == 'd')
				ft_putnbr(va_arg(new, int));
			else if (format[i] == 'i')
				ft_putnbr(va_arg(new, int));
			else if (format[i] == 'u')
				ft_putnbr(va_arg(new, unsigned int));
			else if (format[i] == 'x' || format[i] == 'X')
				ft_putnbr(va_arg(new, int));
		}
		else
			ft_putchar((char)format[i]);
		i++;
	}
	va_end(new);
	return (length);
}
