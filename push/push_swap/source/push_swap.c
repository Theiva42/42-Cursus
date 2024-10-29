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

static void	sorting(t_list **stack_a, t_list **stack_b)
{
	int	pos;
	int	nearest;

	pos = 0;
	if (ft_lstsize(*stack_a) > 3)
	{
		ft_putendl_fd(pb(stack_a, stack_b), STDOUT_FILENO);
		ft_putendl_fd(pb(stack_a, stack_b), STDOUT_FILENO);
	}
	if (ft_lstsize(*stack_a) < 3)
		ft_putendl_fd(pa(stack_a, stack_b), STDOUT_FILENO);
	while (ft_lstsize(*stack_a) > 3)
	{
		count_steps_a(*stack_a);
		count_steps_b(*stack_a, *stack_b);
		sum_steps(*stack_a);
		nearest = get_nearest(*stack_a);
		pos = get_pos(*stack_a, nearest);
		sort(stack_a, stack_b, pos);
	}
	// ft_printf("Size of a in sorting: %d",ft_lstsize(*stack_a));
}

static void	rev_sorting(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_b) > 0)
	{
		count_steps_a(*stack_b);
		count_reverse_steps(*stack_a, *stack_b);
		sum_steps(*stack_b);
		sort_reverse(stack_a, stack_b, 0);
	}
}

static void	sorting_a(t_list **stack_a)
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

	if (ac <= 1)
		return (-1);
	stack_a = (t_list **)calloc(1, sizeof(t_list *));
	stack_b = (t_list **)calloc(1, sizeof(t_list *));
	if (stack_a == NULL || stack_b == NULL)
	{
		free_list(stack_a);
		free_list(stack_b);
		return (0);
	}
	if (!ft_create_stack(stack_a, ac, av))
	{
		free_list(stack_a);
		free_list(stack_b);
		ft_error("Error");
		return (0);
	}
	if (is_list_sorted(*stack_a))
	{
		free_list(stack_a);
		free_list(stack_b);
		return (0);
	}
	// ft_printf("Size of a before: %d",ft_lstsize(*stack_a));
	sorting(stack_a, stack_b);
	// ft_printf("Size of a: %d",ft_lstsize(*stack_a));
	// ft_printf("Size of b: %d",ft_lstsize(*stack_b));
	if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	rev_sorting(stack_a, stack_b);
	sorting_a(stack_a);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
