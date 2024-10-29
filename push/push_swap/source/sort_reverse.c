/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:11:34 by thkumara          #+#    #+#             */
/*   Updated: 2024/10/21 15:11:39 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	handle_negative_steps_sort_reverse(t_list *tmp, t_list **stack_a,
		t_list **stack_b)
{
	if (tmp->steps_a < 0 && tmp->steps_b < 0)
	{
		ft_putendl_fd(rrr(stack_a, stack_b), STDOUT_FILENO);
		tmp->steps_a++;
		tmp->steps_b++;
	}
	else if (tmp->steps_a < 0)
	{
		ft_putendl_fd(rrb(stack_b), STDOUT_FILENO);
		tmp->steps_a++;
	}
	else if (tmp->steps_b < 0)
	{
		ft_putendl_fd(rra(stack_a), STDOUT_FILENO);
		tmp->steps_b++;
	}
}

void	handle_positive_steps_sort_reverse(t_list *tmp, t_list **stack_a,
		t_list **stack_b)
{
	if (tmp->steps_a > 0 && tmp->steps_b > 0)
	{
		ft_putendl_fd(rr(stack_a, stack_b), STDOUT_FILENO);
		tmp->steps_a--;
		tmp->steps_b--;
	}
	else if (tmp->steps_a > 0)
	{
		ft_putendl_fd(rb(stack_b), STDOUT_FILENO);
		tmp->steps_a--;
	}
	else if (tmp->steps_b > 0)
	{
		ft_putendl_fd(ra(stack_a), STDOUT_FILENO);
		tmp->steps_b--;
	}
}	int		len;

void	sort_reverse(t_list **stack_a, t_list **stack_b, int pos)
{
	t_list	*tmp;

	tmp = get_node(*stack_b, pos);
	while (tmp->steps_a != 0 || tmp->steps_b != 0)
	{
		handle_negative_steps_sort_reverse(tmp, stack_a, stack_b);
		handle_positive_steps_sort_reverse(tmp, stack_a, stack_b);
	}
	ft_printf("%s\n",pa(stack_a, stack_b));
}
