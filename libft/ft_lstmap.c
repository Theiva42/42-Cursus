/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:44:26 by thkumara          #+#    #+#             */
/*   Updated: 2024/05/30 12:13:51 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*newlist;
	t_list	*node;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	while (lst != NULL)
	{
		temp = f(lst -> content);
		node = ft_lstnew(temp);
		if (!node)
		{
			del (temp);
			ft_lstclear (&newlist, *del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, node);
		lst = lst -> next;
	}
	return (newlist);
}
