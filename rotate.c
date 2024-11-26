/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:31:56 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/26 13:55:34 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	top = *stack;
	tmp = (*stack)->next;
	tmp->prior = NULL;
	*stack = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = top;
	top->next = NULL;
	top->prior = tmp;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}
