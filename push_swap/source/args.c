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
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*ft_create_arr(char **s)
{
	int	i;
	int	num;
	int	*array;

	i = 0;
	num = 0;
	while (s[i])
		i++;
	array = (int *)malloc(sizeof(int) * (i + 1));
	if (!array)
		ft_error("Error");
	i = 0;
	while (s[i])
	{
		num = ft_atoi(s[i]);
		if (ft_isnum(s[i]) == 1 && ft_is_unique(num, array, i) == 1)
		{	array[i] = num;
			//ft_printf("Array : %d\n", array[i]);
			}
		else
		{
			free(array);
			ft_error("Error");
		}
		i++;
	}
	
	return (array);
}

static void	ft_create_list(t_list **stack, int *array)
{
	int		len;
	int		i;
	t_list	*lst;

	len = 0;
	i = 0;
	while (array[len])
		len++;
	while (i < len)
	{
		lst = ft_lst_new(array[i]);
		ft_lstadd_back(stack, lst);
		i++;
	}
}

void	ft_create_stack(t_list **stack, int ac, char **av)
{
	char	*args;
	char	**args_split;
	int		*array;

	args = ft_copy_args(ac, av);
	args_split = ft_split(args, ' ');
	//ft_printf("Args_split : %s", args_split[0]);
	array = ft_create_arr(args_split);
	//ft_printf("Array : %d", array[0]);
	ft_create_list(stack, array);
	free(array);
	free(args);
	free_all(args_split);
}
