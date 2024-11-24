/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:08:39 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/24 21:15:39 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define NUM_ELEMENTS 500
# define MAX_VALUE 10000

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				index;
	int				value;
	int				cost;
	bool			up_middle;
	bool			cheapest;
	struct s_stack	*purpose_node;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

// *** utils
long				ft_atoi(const char *str);
char				**ft_split(char const *s, char c);
void				ft_putendl_fd(char *s, int fd);
// fill_stack.c
void				init(t_stack **stack_a, char **nums, int ac);
void				fill_stack(t_stack **stack_a, int nbr);
// *** sets.c
void				set_cost(t_stack *stack_a, t_stack *stack_b);
void				set_cheapest(t_stack *stack_b);
void				set_index(t_stack *stack);
void				set_purpose(t_stack *stack_a, t_stack *stack_b);
// *** gets.c
t_stack				*get_cheapest(t_stack *stack);
t_stack				*get_min(t_stack *stack);
int					get_size(t_stack *stack);
// sorting.c
int					find_max(t_stack *stack);
bool				is_sorted(t_stack *stack_a);
void				sort_3(t_stack **stack);
void				big_sort(t_stack **stack_a, t_stack **stack_b);
// checkers.c
int					ft_is_integer(int nbr);
int					ft_is_duplicate(t_stack *stack, int nbr);
int					ft_is_digit(char *s);
int					catch_error(t_stack **stack, char *nums, long nbr);
void				free_all(t_stack **a, char **nums, int ac);
// *** operators ***
// swap.c
void				swap(t_stack **stack);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
// push.c
void				push(t_stack **dest_stack, t_stack **src_stack);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
// rotate.c
void				rotate(t_stack **stack);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
// reverse_rotate.c
void				reverse_rotate(t_stack **stack);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
// push_swap.c
void				repeat_rotate(t_stack **stack, t_stack *purpose, char c);
void				replace(t_stack **stack_a, t_stack **stack_b);
void				push_swap(t_stack **stack_a, t_stack **stack_b);

#endif
