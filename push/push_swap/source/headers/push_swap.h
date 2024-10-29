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

# include "headers/ft_printf.h"
# include "headers/libft.h"

// Stack
typedef struct s_list
{
	int				index;
	int				value;
	int				steps_a;
	int				steps_b;
	int				total;
	struct s_list	*next;
}					t_list;

// HELPER FORBIDEN FUNCTIONS
void				print_list(t_list *lst);
void				display_lst(t_list *stack_a, t_list *stack_b);
void				display_lst_reverse(t_list *stack_a, t_list *stack_b);
void				print_double_p(char **s);
void				print_array_of_int(int *num, int len);

// UTILS
void				ft_error(char *msg);
void				free_all(char **s);
int					is_list_sorted(t_list *lst);
int					ft_lstsize(t_list *lst);
t_list				*get_node(t_list *stack, int pos);
int					get_min(t_list *lst);
int					get_max(t_list *lst);
int					get_pos(t_list *lst, int num);
void				free_list(t_list **list);

// ARGS FUNCTIONS:
char				*ft_copy_args(int ac, char **av);
int					ft_is_unique(int num, int *array, int len);
int					is_validable(char *s);
int					*ft_create_args(char **s);
t_list				*ft_lst_new(int value);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_init_stack(t_list **stack, int ac, char **av);

// MOVES:
int					r_rotate(t_list **lst);
char				*rra(t_list **stack_a);
char				*rrb(t_list **stack_b);
char				*rrr(t_list **stack_a, t_list **stack_b);
int					rotate(t_list **lst);
char				*ra(t_list **stack_a);
char				*rb(t_list **stack_b);
char				*rr(t_list **stack_a, t_list **stack_b);
int					push(t_list **src, t_list **dst);
char				*pa(t_list **stack_a, t_list **stack_b);
char				*pb(t_list **stack_a, t_list **stack_b);
int					swap(t_list **stack);
char				*sa(t_list **stack_a);
char				*sb(t_list **stack_b);
char				*ss(t_list **stack_a, t_list **stack_b);

// SORT:
void				count_steps_a(t_list *stack_a);
void				sort_three(t_list **lst);
int					get_target(t_list *stack_a, t_list *stack_b, int size_b);
void				count_steps_b(t_list *stack_a, t_list *stack_b);
int					get_reverse_target(t_list *dst, t_list *src, int size_dst);
void				count_reverse_steps(t_list *dst, t_list *src);
void				sum_steps(t_list *stack_a);
int					get_cheapest(t_list *stack_a);
void				sort(t_list **stack_a, t_list **stack_b, int pos);
void				sort_reverse(t_list **stack_a, t_list **stack_b, int pos);
void				sort_a(t_list **stack_a, int pos);

#endif
