/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:31:56 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/24 21:40:54 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp_first;

	if ((*stack)->next == NULL || *stack == NULL)
		return ;
	tmp_first = *stack; // store address of the head_node
	tmp = (*stack)->next;
	*stack = tmp;
	while (tmp->next) // go to the end of the stack, while node has next node, when next = NULL, exit from the loop
		tmp = tmp->next;
	tmp->next = tmp_first;
	tmp_first->previous = tmp;
	tmp_first->next = NULL;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra\n", 1);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr\n", 1);
}
