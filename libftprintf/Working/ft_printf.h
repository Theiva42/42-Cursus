/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:00:00 by thkumara          #+#    #+#             */
/*   Updated: 2024/06/10 14:04:22 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int ft_inttohex(unsigned int num, int x);
int ft_putchar(char c);
int ft_putstr(char *str);
char    *ft_strchr(const char *s, int c);
int ft_putunsigned(unsigned int num);
int	ft_putnbr(int nb);
int ft_putptr(unsigned long num);

#endif
