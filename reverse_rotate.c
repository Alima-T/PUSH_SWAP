/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:10:10 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/24 21:51:54 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp_last;

	if ((*stack)->next == NULL || *stack == NULL)
		return ;
	tmp_last = *stack;     // store address of the head_node, which must go to the end of the stack
	while (tmp_last->next) // go to the end of the stack, while node has next node, when next = NULL, exit from the loop
		tmp_last = tmp_last->next;
	tmp = tmp_last->previous;      // store address of previous node
	tmp->next = NULL;              // make next adress NULL to finish new stack
	tmp_last->previous = NULL;     // now last  is on the top,	we make previous address NULL
	tmp_last->next = *stack;       // store the head on the next node
	(*stack)->previous = tmp_last;		// make previouse address of head = adres of last,which now moved to the top
	*stack = tmp_last;             // replace head to the new head.
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putendl_fd("rra\n", 1);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr\n", 1);
}
