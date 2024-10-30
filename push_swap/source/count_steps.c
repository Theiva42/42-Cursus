/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:10:58 by thkumara          #+#    #+#             */
/*   Updated: 2024/10/21 15:11:02 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	count_steps_a(t_list *stack_a)
{
	int	pos;
	int	size_lst;

	if (stack_a == NULL)
		return ;
	size_lst = ft_lstsize(stack_a);
	pos = 0;
	while (stack_a)
	{
		if (pos < (size_lst / 2))
		{
			stack_a->steps_a = pos;
		}
		else
		{
			stack_a->steps_a = pos - size_lst;
		}
		stack_a = stack_a->next;
		pos++;
	}
}

int	get_target(t_list *stack_a, t_list *stack_b)
{
	int	max_value_b;
	int	min_value_b;

	if (!stack_a || !stack_b)
		return (0);
	min_value_b = get_min(stack_b);
	max_value_b = get_max(stack_b);
	if (stack_a->value < min_value_b)
		return (min_value_b);
	if (stack_a->value > max_value_b)
		return (max_value_b);
	while (stack_b && stack_b->next)
		{
			if (stack_a->value > stack_b->value && stack_a->value < stack_b->next->value)
				return (stack_b->next->value);
			stack_b = stack_b->next;
		}
	return (min_value_b);
}

void	count_steps_b(t_list *stack_a, t_list *stack_b)
{
	int	size_b;
	int	target;
	int position;

	if (stack_a == NULL || stack_b == NULL)
	 	return ;
	size_b = ft_lstsize(stack_b);
	while (stack_a)
	{
		target = get_target(stack_a, stack_b);
		// ft_printf ("Target of %d is %d", stack_a->value, target);
		position = get_pos(stack_b, target);
		// ft_printf("position is %d of %d", position, target);
		if (position != -1)
		{
			if (position < size_b / 2)
				stack_a->steps_b = position;
			else
				stack_a->steps_b = -(size_b - position);
		}
		stack_a = stack_a->next;
	}
}
