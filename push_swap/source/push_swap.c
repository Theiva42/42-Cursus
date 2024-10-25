/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:03:21 by thkumara          #+#    #+#             */
/*   Updated: 2024/10/21 15:07:52 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	loop(t_list **stack_a, t_list **stack_b)
{
	int	pos;
	int	cheapest;

	pos = 0;
	if (ft_lstsize(*stack_a) > 3)
	{
		ft_printf("%s\n", pb(stack_a, stack_b));
		ft_printf("%s\n", pb(stack_a, stack_b));
	}
	while (ft_lstsize(*stack_a) > 3)
	{
		count_steps_a(*stack_a);
		count_steps_b(*stack_a, *stack_b);
		sum_steps(*stack_a);
		cheapest = get_cheapest(*stack_a);
		pos = get_pos(*stack_a, cheapest);
		sort(stack_a, stack_b, pos);
	}
}

static void	rev_loop(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_b) > 0)
	{
		count_steps_a(*stack_b);
		count_reverse_steps(*stack_a, *stack_b);
		sum_steps(*stack_b);
		sort_reverse(stack_a, stack_b, 0);
	}
}

static void	loop_a(t_list **stack_a)
{
	int	pos;

	pos = 0;
	if (is_list_sorted(*stack_a) == 0)
	{
		count_steps_a(*stack_a);
		pos = get_pos(*stack_a, get_min(*stack_a));
		sort_a(stack_a, pos);
	}
}

int	main(int ac, char *av[])
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac < 1)
	{
		ft_error("Error");
		return (-1);
	}
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	ft_create_stack(stack_a, ac, av);
	if (is_list_sorted(*stack_a))
	{
		free_list(stack_a);
		free_list(stack_b);
		return (0);
	}
	else
	{
		loop(stack_a, stack_b);
		if (ft_lstsize(*stack_a) == 3)
			sort_three(stack_a);
		rev_loop(stack_a, stack_b);
		loop_a(stack_a);
	}
	if (stack_a)
		free_list(stack_a);
	if (stack_b)
		free_list(stack_b);
	return (0);
}
