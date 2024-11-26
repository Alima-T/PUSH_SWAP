/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:10:10 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/26 13:53:13 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*end;
	t_stack	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	end = *stack;
	while (end->next)
		end = end->next;
	tmp = end->prior;
	end->prior = NULL;
	end->next = *stack;
	tmp->next = NULL;
	(*stack)->prior = end;
	*stack = end;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
