/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:09:22 by thkumara          #+#    #+#             */
/*   Updated: 2024/10/21 15:09:27 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_reverse_target(t_list *dst, t_list *src, int size_dst)
{
	int	target;
	int	src_value;
	int	last_value_dst;
	int	first_value_dst;

	src_value = src->value;
	if (src_value < get_min(dst) || src_value > get_max(dst))
		target = get_min(dst);
	else
	{
		first_value_dst = get_node(dst, 0)->value;
		last_value_dst = get_node(dst, size_dst - 1)->value;
		while (dst->next)
		{
			if (src_value > dst->value && src_value < dst->next->value)
				target = dst->next->value;
			else if (src_value > last_value_dst && src_value < first_value_dst)
				target = first_value_dst;
			dst = dst->next;
		}
	}
	return (target);
}

void	count_reverse_steps(t_list *dst, t_list *src)
{
	int	size_dst;
	int	target;

	size_dst = ft_lstsize(dst);
	while (src)
	{
		target = get_reverse_target(dst, src, size_dst);
		if (get_pos(dst, target) <= size_dst / 2)
		{
			src->steps_b = get_pos(dst, target);
		}
		else
		{
			src->steps_b = -(size_dst - get_pos(dst, target));
		}
		src = src->next;
	}
}

void	sum_steps(t_list *stack_a)
{
	while (stack_a)
	{
		if ((stack_a->steps_a < 0 && stack_a->steps_b < 0)
			|| (stack_a->steps_a > 0 && stack_a->steps_b > 0))
		{
			// ft_printf("Stack_a->Steps_b : %d & ABS Stack_a->Step_b : %d\n", stack_a->steps_b, abs(stack_a->steps_b));
			// ft_printf("Stack_a->Steps_a : %d & ABS Stack_a->Step_a : %d\n", stack_a->steps_a, abs(stack_a->steps_a));
			if (abs(stack_a->steps_a) > abs(stack_a->steps_b))
				stack_a->total = abs(stack_a->steps_a);
			else
				stack_a->total = abs(stack_a->steps_b);
		}
		else
		{
			// ft_printf("stack total: %d + %d = %d\n", stack_a->steps_a, stack_a->steps_b, abs(stack_a->steps_a) + abs(stack_a->steps_b));
			stack_a->total = abs(stack_a->steps_a) + abs(stack_a->steps_b);
		}
		stack_a = stack_a->next;
	}
}

// int	get_nearest(t_list *stack_a)
// {
// 	int	min;
// 	int	value_min;

// 	if (stack_a)
// 	{
// 		min = stack_a->total;
// 		value_min = stack_a->value;
// 		stack_a = stack_a->next;
// 	}
// 	while (stack_a)
// 	{
// 		if (stack_a->total < min)
// 		{
// 			min = stack_a->total;
// 			value_min = stack_a->value;
// 		}
// 		stack_a = stack_a->next;
// 	}
// 	return (value_min);
// }
