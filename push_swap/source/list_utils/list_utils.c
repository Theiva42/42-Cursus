/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:28:12 by thkumara          #+#    #+#             */
/*   Updated: 2024/10/21 13:01:24 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	*ft_lst_new(int value)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	//node->index = -1;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*end;

	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
			end = lst;
		lst = lst->next;
	}
	return (end);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = ft_lstlast(*lst);
		ptr -> next = new;
	}
}

int	check_list_order(t_list *lst)
{
	if (!lst)
		ft_error("Error");
	while (lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}
