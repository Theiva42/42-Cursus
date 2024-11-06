/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:16:17 by thkumara          #+#    #+#             */
/*   Updated: 2024/10/21 14:05:26 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		length;

	length = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		lst = lst -> next;
		length ++;
	}
	return (length);
}

t_list	*get_node(t_list *lst, int pos)
{
	int		i;
	t_list	*node;

	i = 0;
	node = lst;
	while (i < pos)
	{
		node = node->next;
		i++;
	}
	return (node);
}

int	get_min(t_list *lst)
{
	int	min;

	if (lst)
	{
		min = lst->value;
		lst = lst->next;
	}
	while (lst)
	{
		if (lst->value < min)
			min = lst->value;
		lst = lst->next;
	}
	return (min);
}

int	get_max(t_list *lst)
{
	int	max;

	if (lst)
	{
		max = lst->value;
		lst = lst->next;
	}
	while (lst)
	{
		if (lst->value > max)
			max = lst->value;
		lst = lst->next;
	}
	return (max);
}

int	get_pos(t_list *lst, int num)
{
	int	pos;

	pos = 0;
	while (lst != NULL)
	{
		if (lst->value == num)
			return (pos);
		pos++;
		lst = lst->next;
	}
	return (-1);
}
