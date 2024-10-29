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

int	get_reverse_target(t_list *dst, t_list *src)
{
	int	max_value_dst;
	int	min_value_dst;

	if (!dst || !src)
		return (0);
	max_value_dst = get_max(dst);
	min_value_dst = get_min(dst);
	if (src->value < min_value_dst || src->value > max_value_dst)
		return (min_value_dst);
	while (dst && dst->next)
		{
			if (src->value > dst->value && src->value < dst->next->value)
				return (dst->next->value);
			dst = dst->next;
		}
	return (max_value_dst);
}

void	count_reverse_steps(t_list *dst, t_list *src)
{
	int	size_dst;
	int	target;
	int pos;

	if (dst == NULL || src == NULL)
		return ;
	size_dst = ft_lstsize(dst);
	while (src)
	{
		target = get_reverse_target(dst, src);
		pos = get_pos(dst, target);
		if (pos != -1)
		{
			if (pos <= size_dst / 2)
				src->steps_b = pos;
			else
				src->steps_b = -(size_dst - pos);
		}
		src = src->next;
	}
}

void	sum_steps(t_list *stack_a)
{
	if (stack_a == NULL || !stack_a->steps_a || !stack_a->steps_b)
		return ;
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

int	get_nearest(t_list *stack_a)
{
	int	min;
	int	value_min;

	if (stack_a == NULL || !stack_a->next)
	 	return (-1);
	if (stack_a && stack_a->next)
	{
		min = stack_a->total;
		value_min = stack_a->value;
		stack_a = stack_a->next;
	}
	while (stack_a != NULL)
	{
		// ft_printf ("Stack_a->Total is %d, min %d", stack_a->total, min);
		if (stack_a->total < min)
		{
			min = stack_a->total;
			value_min = stack_a->value;
		}
		stack_a = stack_a->next;
	}
	// ft_printf ("Return nearest value is %d", value_min);
	return (value_min);
}