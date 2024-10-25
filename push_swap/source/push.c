/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:27:21 by thkumara          #+#    #+#             */
/*   Updated: 2024/10/21 11:37:41 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	push(t_list **source, t_list **dest)
{
	t_list	*temp;

	temp = *dest;
	*dest = *source;
	*source = (*source)->next;
	(*dest)->next = temp;
	return (1);
}

char	*pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == 0)
		return (NULL);
	return ("pa");
}

char	*pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == 0)
		return (NULL);
	return ("pb");
}
