/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:22:23 by thkumara          #+#    #+#             */
/*   Updated: 2024/06/10 12:36:11 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include<stdarg.h>
//#include<stdio.h>
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

int ft_printf(const char *format, ...)
{
    va_list new;
    int i;
    int value;
    int j;

    i = 0;
    va_start (new, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {    
            i++;
            if (format[i] == '%')
               ft_putchar('%'); 
            if (format[i] == '0')
            {
                value = 0;
                j = i;
                while (format[j] == '.')
                {
                    while(value < format[j])
                    {
                        ft_putchar('0');
                        value++;
                    }
                    j++;
                }               
                while (value < format[j] && format[j] != '.')
                    {
                        ft_putchar('0');
                        value++;
                        j++;
                    }
                ft_putnbr(va_arg(new, int));
            }
            else
            {
                if (format[i] == 'c')
                    ft_putchar(va_arg(new, int));
                else if (format[i] == 's')
                    ft_putstr(va_arg(new, char*));
                else if (format[i] == 'p')
                    ft_putchar(va_arg(new, int));
                else if (format[i] == 'd')
                    ft_putnbr(va_arg(new, int));
                else if (format[i] == 'i')
                    ft_putnbr(va_arg(new, int));
                else if (format[i] == 'u')
                    ft_putnbr(va_arg(new, unsigned int));
                else if (format[i] == 'x' || format[i] == 'X')
                    ft_putnbr(va_arg(new, int));
                if (format[i] == '#')
                {
                    i++;
                    value = va_arg(new, int);
                    if (format[i] == 'x' && value != 0)
                        ft_putstr("0x");
                    else if (format[i] == 'X' && value != 0)
                        ft_putstr("0X");
                    ft_putnbr(value);
                }
            }
            
        }
        else
            ft_putchar((char)format[i]);
        i++;
    }
    va_end(new);
    return (0);
}

/*int main(void)
{
    int s[] = {1,2,3,4,5};
    int i = 0;
    while (s[i] != '\0')
    {
    printf("Default1 : Hello %s!\n", "Theiva");     // Left-justified, minimum width 10
    printf("Default2 : %i\n", i);      
    printf("Default3 : %#x\n", i);        // Alternate form for hexadecimal
    printf("Default4 : %04.3d\n", i);              // Force sign, minimum width 8, precision 2, padded with zeros
    printf("Default5 : %%\n");  
    //printf("Default4 :%10.5s\n", "Hello"); // Minimum width 10, precision 5 for string

    ft_printf("My function1 : Hello %s!\n", "Theiva");     // Left-justified, minimum width 10
    ft_printf("My function2 : %i\n", i);      // Force sign, minimum width 8, precision 2, padded with zeros
    ft_printf("My Function3 : %#x\n", i);        // Alternate form for hexadecimal
    ft_printf("My function4 : %04.3d\n", i);            // Force sign, minimum width 8, precision 2, padded with zeros
    ft_printf("My Function5 : %%\n");
    //ft_printf("My Function4 :%10.5s\n", "Hello"); // Minimum width 10, precision 5 for string
    i++;
    }
}*/

