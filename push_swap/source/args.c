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

int	ft_isnum(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-')
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

int	*ft_create_arr(char **s)
{
	int	i;
	long	num;
	int	*array;

	i = 0;
	num = 0;
	while (s[i])
		i++;
	array = (int *)calloc(1, sizeof(int) * (i + 1));
	if (!array)
		ft_error("Error");
	i = 0;
	while (s[i])
	{
		num = ft_atoi(s[i]);
		if (num > 2147483647 || num < -2147483647)
		{
			free(array);
			return (0);
		}
		if (ft_isnum(s[i]) == 1 && ft_is_unique(num, array, i) == 1)
		{	array[i] = num;
			//ft_printf("Array : %d\n", array[i]);
			}
		else
		{
			free(array);
			return (0);
		}
		i++;
	}
	
	return (array);
}

static void	ft_create_list(t_list **stack, int *array)
{
	int		i;
	int		size;
	t_list	*lst;

	i = 0;
	size = 0;
	if (!stack || !array)
		return ;
	while(array[size])
		size++;
	while (i < size)
	{
		lst = ft_lst_new(array[i]);
		ft_lstadd_back(stack, lst);
		i++;
	}
}

int	ft_create_stack(t_list **stack_a, int ac, char **av)
{
	char	*argstr;
	char	**args_split;
	int		*array;

	args_split = NULL;
	array = NULL;
	argstr = ft_argstostr(ac, av);
	if (argstr) 
		args_split = ft_split(argstr, ' ');
	//ft_printf("Args_split : %s", args_split[0]);
	if (args_split)
		array = ft_create_arr(args_split);
	else
	{
		free(array);
		free(argstr);
		free_all(args_split);
		return (0);
	}
	//ft_printf("Array : %d", array[0]);
	if (array)
		ft_create_list(stack_a, array);
	else
	{
		free(array);
		free(argstr);
		free_all(args_split);
		return (0);
	}
	free(array);
	free(argstr);
	free_all(args_split);
	return (1);
}
