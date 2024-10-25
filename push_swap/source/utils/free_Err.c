/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:07:43 by thkumara          #+#    #+#             */
/*   Updated: 2024/10/21 14:12:37 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_error(char	*msg)
{
	ft_printf("Error");
	exit (EXIT_FAILURE);
}

void	free_all(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free (s[i++]);
	free (s);
}

void	free_list(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free (*lst);
		*lst = temp;
	}
	free (lst);
}
