/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:08:39 by aokhapki          #+#    #+#             */
/*   Updated: 2024/06/21 21:58:34 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_stack
{
	int					value;
	int					current_position;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*previous;
}						t_stack;

//Handle errors
void		error_duplicate(t_stack *a);
void		free_errors(t_stack **a, int error);
void		print_error(void);
int			error_not_num(char *a);

//Stack initiation

void		stack_create(t_stack **a, char **argv);
void		stack_init(t_stack **a, char **argv);
void		append_node(t_stack **stack, int nb);

//Sorting

void		sort_a(void);
void		sort_b(void);
void		sort_3(t_stack **a);
void		sort_till_3(void);
void		final_sort_big(t_stack **a, t_stack **b);

static void	swap(t_stack **stack);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

static void	push(t_stack **dest, t_stack **source);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);

static void	rotate(t_stack **stack);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

static void	reverse_rotate(t_stack **stack);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

//Commands

//Algorithms

#endif