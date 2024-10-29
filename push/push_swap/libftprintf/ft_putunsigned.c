/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:29:58 by thkumara          #+#    #+#             */
/*   Updated: 2024/06/20 12:33:49 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunsigned(unsigned int num)
{
	int	count;

	count = 0;
	if (num >= 10)
		count += ft_putunsigned(num / 10);
	count += ft_putchar(num % 10 + 48);
	return (count);
}
