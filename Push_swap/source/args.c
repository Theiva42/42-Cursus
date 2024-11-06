/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:08:00 by thkumara          #+#    #+#             */
/*   Updated: 2024/10/21 15:08:11 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(int *array, char *argstr, char **args_split)
{
	if (array)
		free(array);
	if (argstr)
		free(argstr);
	if (args_split)
		free_all(args_split);
}

int	ft_isnum(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-' && s[1] != '\0')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*ft_create_arr(char **s)
{
	int		i;
	int		*array;
	long	num;

	i = 0;
	num = 0;
	while (s[i])
		i++;
	array = (int *)ft_calloc(1, sizeof(int) * (i + 1));
	i = -1;
	while (s[++i])
	{
		if (ft_isnum(s[i]) == 0)
			return (free(array), NULL);
		num = ft_atoi(s[i]);
		if (num > 2147483647 || num < -2147483648)
			return (free(array), NULL);
		if (ft_is_unique(num, array, i) == 1)
			array[i] = num;
		else
			return (free(array), NULL);
	}
	return (array);
}

static void	ft_create_list(t_list **stack_a, t_list **stack_b,
							int *array, char **args_split)
{
	t_list	*lst;
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (!stack_a || !array)
		return ;
	while (args_split[size])
		size++;
	while (i < size)
	{
		lst = ft_lst_new(array[i]);
		if (lst == NULL)
		{
			free_list (stack_b);
			return ;
		}
		ft_lstadd_back(stack_a, lst);
		i++;
	}
}

int	ft_create_stack(t_list **stack_a, t_list **stack_b, int ac, char **av)
{
	char	*argstr;
	char	**args_split;
	int		*array;

	args_split = NULL;
	array = NULL;
	argstr = ft_argstostr(ac, av);
	if (argstr)
		args_split = ft_split(argstr, ' ');
	else
		return (ft_free(array, argstr, args_split), 0);
	if (args_split)
		array = ft_create_arr(args_split);
	else
		return (ft_free(array, argstr, args_split), 0);
	if (array)
		ft_create_list(stack_a, stack_b, array, args_split);
	else
		return (ft_free(array, argstr, args_split), 0);
	ft_free(array, argstr, args_split);
	return (1);
}
