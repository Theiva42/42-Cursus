/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:39:57 by thkumara          #+#    #+#             */
/*   Updated: 2024/10/21 11:45:09 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!stack || ft_lstsize(*stack) <= 1)
		return (0);
	temp1 = *stack;
	temp2 = temp1->next;
	temp1->next = temp2->next;
	(*stack) = temp2;
	temp2->next = temp1;
	return (1);
}

char	*sa(t_list **stack_a)
{
	if (swap(stack_a) == 0)
		return (NULL);
	return ("sa");
}

char	*sb(t_list **stack_b)
{
	if (swap(stack_b) == 0)
		return (NULL);
	return ("sb");
}

char	*ss(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a) == 0 && swap(stack_b) == 0)
		return (NULL);
	return ("ss");
}
