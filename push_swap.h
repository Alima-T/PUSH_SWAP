/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:08:39 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/26 13:33:41 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./LIBFT/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define RED "\033[1;31m"
# define CYAN "\033[1;36m"
# define GRN "\033[1;32m"
# define BLUE "\033[1;34m"
# define MAG "\033[1;35m"
# define YEL "\033[1;33m"
# define BOLD "\033[1m"
# define UNDERLINE "\033[4m"
# define RESET "\033[0m"

typedef struct s_stack
{
	int				index;
	int				val;
	int				cost;
	bool			up_middle;
	bool			cheap;
	struct s_stack	*focus_node;
	struct s_stack	*prior;
	struct s_stack	*next;
}					t_stack;

// *** fill_stack.c
int					ft_isspace(int c);
long				ft_atol(const char *str);
void				init(t_stack **a, char **nums, int ac);
void				fill_stack(t_stack **a, int nbr);
// *** sets.c
void				set_cost(t_stack *a, t_stack *b);
void				set_cheap(t_stack *b);
void				set_index(t_stack *stack);
void				set_focus(t_stack *a, t_stack *b);
// gets.c
int					get_size(t_stack *stack);
t_stack				*get_min(t_stack *stack);
t_stack				*get_min_cost(t_stack *b);
// sorting.c
int					find_max(t_stack *a);
void				sort_3(t_stack **a);
void				big_sort(t_stack **a, t_stack **b);
bool				is_sorted(t_stack *a);
// checkers.c
int					ft_is_number(char *num);
int					ft_is_reapeated(t_stack *a, int nbr);
int					check_error(t_stack **a, long nbr, char *nums);
void				free_all(t_stack **a, int ac, char **nums);
// push_swap.c
void				push_swap(t_stack **a, t_stack **b);
void				replace(t_stack **a, t_stack **b);
void				repeat_rotate(t_stack **stack, t_stack *focus, char c);
// *** operators ***
// push.c
void				push(t_stack **dest, t_stack **src);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
// swap.c
void				swap(t_stack **stack);
void				sa(t_stack **a);
void				sb(t_stack **b);
// rotate.c
void				rotate(t_stack **stack);
void				ra(t_stack **a);
void				rb(t_stack **b);
// reverse_rotate.c
void				reverse_rotate(t_stack **stack);
void				rra(t_stack **a);
void				rrb(t_stack **b);
// double_operators.c
void				rrr(t_stack **a, t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				ss(t_stack **a, t_stack **b);

#endif
