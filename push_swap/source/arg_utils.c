/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:10:08 by thkumara          #+#    #+#             */
/*   Updated: 2024/10/21 15:10:12 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_len(char **s)
{
	int	len;
	int	i;

	i = 1;
	len = 0;
	while (s[i])
	{
		len += ft_strlen(s[i]);
		i++;
	}
	return (len);
}

char	*ft_argstostr(int ac, char **av)
{
	int		i;
	int		len;
	char	*args;
	int		j;
	int		k;

	len = get_len(av);
	args = (char *)malloc(sizeof(char) * (len + 1 + ac));
	if (!args)
		ft_error("Error");
	i = 1;
	j = 0;
	k = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			args[k++] = av[i][j++];
		i++;
		if (i < ac)
			args[k++] = ' ';
		else
			args[k++] = '\0';
	}
	return (args);
}

int	ft_is_unique(int num, int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (num == array[i])
			return (0);
		i++;
	}
	return (1);
}
