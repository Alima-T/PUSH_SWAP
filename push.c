/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:48:34 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/23 18:24:38 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dest_stack, t_stack **src_stack)
{
	t_stack *tmp;
	
	if(*src_stack == NULL) // if stack is empty
		return ;
	tmp = *src_stack; // store head of source stack
	*src_stack = (*src_stack)->next; // make head of stack next node, becouse we are going to push top to another stack
	tmp->next = *dest_stack; // make next of top node, which we are pushing, head of ctack where we push it
	if(*dest_stack) // if stack is not empty
		(*dest_stack)->previous = tmp; //make previous, which was NULL, new node tmp
	tmp->previous = NULL; // make NULL, but it is maybe redundant, it was NULL
	*dest_stack = tmp;
	
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pa\n", 1);
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pb\n", 1);
}