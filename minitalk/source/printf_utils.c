/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:30:58 by thkumara          #+#    #+#             */
/*   Updated: 2024/11/03 16:31:09 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	ft_handle_pointer(va_list ap)
{
	void	*n;

	n = va_arg(ap, void *);
	write(1, "0x", 2);
	return (ft_putnbr_base((unsigned long long)n, "0123456789abcdef") + 2);
}

int	ft_handle_string(va_list ap)
{
	char	*s;
	int		i;
	int		ret;

	s = va_arg(ap, char *);
	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	ret = 0;
	while (s[i])
	{
		ret = write(1, &s[i], 1);
		if (ret == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_handle_unsigned(va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	return (ft_putnbr_base(n, "0123456789"));
}
