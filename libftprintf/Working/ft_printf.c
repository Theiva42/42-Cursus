/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:39:31 by thkumara          #+#    #+#             */
/*   Updated: 2024/06/11 16:59:21 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		str = "(null)";
	while (str[len] != '\0')
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}

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

int	ft_inttohex(unsigned int num, int x)
{
	char hexnum[17];
	int count;
	int i;
	
	i = 0;
	if (num == 0) 
		return (ft_putchar('0'));
	while (num != 0)
	{		
		if (num != 0 && x == 0)
			hexnum[i] = "0123456789abcdef"[num % 16];
		else if (num != 0 && x == 1)
			hexnum[i] = "0123456789ABCDEF"[num % 16];
		num /= 16;
		i++;
	}
	hexnum[i] = '\0';
	count = i;
	while ( i >= 0)
		ft_putchar(hexnum[i--]);
	return (count);
}

static int	ft_formatcheck(char fs, va_list new)
{
	unsigned long	temp;

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

int main(void)
{
    //int s[] = {1,2,3,4,5};
    char *s2 = "aaadd";
	int i = 5154;
    //while (s[i] != '\0')
    //{
    //int rets = printf(" NULL %s NULL ", NULL);     // Left-justified, minimum width 10
   // int retd = printf("Default2 :%d \n", -10);      // Force sign, minimum width 8, precision 2, padded with zeros
    int retx = printf(" %u ", -9);        // Alternate form for hexadecimal
    //int retp = printf(" %p ", 1); // Minimum width 10, precision 5 for string
	//printf("Default5 :%u\n", i);
	//printf(" NULL %s NULL ", NULL);

    //int rets1 = ft_printf(" NULL %s NULL ", NULL);     // Left-justified, minimum width 10
    //int retd1 = ft_printf("My function2 :%d\n", -10);      // Force sign, minimum width 8, precision 2, padded with zeros
    int retx1 = ft_printf(" %u ", -9);        // Alternate form for hexadecimal
    //int retp1 = ft_printf(" %p ", 1); // Minimum width 10, precision 5 for string
    //ft_printf("My Function5 :%u\n", i);
	//ft_printf(" NULL %s NULL ", NULL);
	//i++;
    //}
	if (retx == retx1)
		printf("True x %d,%d\n", retx,retx1);
	else
		printf("False x %d,%d\n", retx,retx1);

	//if (retd == retd1)
	//	printf("True d \n");
	//else
	//	printf("False s %d,%d\n", retd,retd1);
}
