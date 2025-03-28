/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:03:19 by thkumara          #+#    #+#             */
/*   Updated: 2024/10/21 12:26:18 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	r_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (!*stack || ft_lstsize(*stack) <= 1)
		return (0);
	head = *stack;
	tail = ft_lstlast(head);
	while (head->next && head->next->next)
		head = head->next;
	head->next = NULL;
	tail->next = *stack;
	*stack = tail;
	return (1);
}

char	*rra(t_list **stack_a)
{
	if (r_rotate(stack_a) == 0)
		return (NULL);
	return ("rra");
}

char	*rrb(t_list **stack_b)
{
	if (r_rotate(stack_b) == 0)
		return (NULL);
	return ("rrb");
}

char	*rrr(t_list **stack_a, t_list **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	return ("rrr");
}
