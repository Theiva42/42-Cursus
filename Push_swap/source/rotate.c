/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:50:02 by thkumara          #+#    #+#             */
/*   Updated: 2024/10/21 12:01:34 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	rotate(t_list **stack)
{
	t_list	*new;

	if (!*stack || ft_lstsize(*stack) <= 1)
		return (0);
	new = *stack;
	*stack = (*stack)->next;
	new->next = NULL;
	ft_lstadd_back(stack, new);
	return (1);
}

char	*ra(t_list **stack_a)
{
	if (rotate(stack_a) == 0)
		return (NULL);
	return ("ra");
}

char	*rb(t_list **stack_b)
{
	if (rotate(stack_b) == 0)
		return (NULL);
	return ("rb");
}

char	*rr(t_list **stack_a, t_list **stack_b)
{
	rotate (stack_a);
	rotate (stack_b);
	return ("rr");
}
