/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:16:29 by thkumara          #+#    #+#             */
/*   Updated: 2024/06/20 12:33:37 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(char *str)
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
