/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:00:39 by thkumara          #+#    #+#             */
/*   Updated: 2024/10/21 15:01:40 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

// Stack
typedef struct s_list
{
	int				value;
	int				steps_a;
	int				steps_b;
	int				total;
	struct s_list	*next;
}					t_list;

// FREE FUNCTIONS
void				ft_error(char *msg);
void				free_all(char **s);
void				free_list(t_list **list);

// GET FUNCTIONS
t_list				*get_node(t_list *stack, int pos);
int					get_min(t_list *lst);
int					get_max(t_list *lst);
int					get_pos(t_list *lst, int num);

// LIST FUNCTIONS
int					is_list_sorted(t_list *lst);
int					ft_lstsize(t_list *lst);
t_list				*ft_lst_new(int value);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);

// STACK FUNCTIONS
char				*ft_argstostr(int ac, char **av);
int					ft_create_stack(t_list **stack_a, t_list **stack_b,
						int ac, char **av);
int					*ft_create_arr(char **s);
int					ft_is_unique(int num, int *array, int len);
int					ft_isnum(char *s);

// MOVE FUNCTION
int					push(t_list **src, t_list **dst);
int					swap(t_list **stack);
int					rotate(t_list **lst);
int					r_rotate(t_list **lst);
char				*ra(t_list **stack_a);
char				*rb(t_list **stack_b);
char				*rr(t_list **stack_a, t_list **stack_b);
char				*pa(t_list **stack_a, t_list **stack_b);
char				*pb(t_list **stack_a, t_list **stack_b);
char				*sa(t_list **stack_a);
char				*sb(t_list **stack_b);
char				*ss(t_list **stack_a, t_list **stack_b);
char				*rra(t_list **stack_a);
char				*rrb(t_list **stack_b);
char				*rrr(t_list **stack_a, t_list **stack_b);

// SORT FUNCTION
void				count_steps_a(t_list *stack_a);
void				count_steps_b(t_list *stack_a, t_list *stack_b);
void				count_reverse_steps(t_list *dst, t_list *src);
void				sum_steps(t_list *stack_a);
void				sort(t_list **stack_a, t_list **stack_b, int pos);
void				sort_reverse(t_list **stack_a, t_list **stack_b, int pos);
void				sort_a(t_list **stack_a, int pos);
void				sort_three(t_list **lst);
int					get_target(t_list *stack_a, t_list *stack_b);
int					get_reverse_target(t_list *dst, t_list *src);
int					get_nearest(t_list *stack_a);
int					ft_abs(int num);

#endif
