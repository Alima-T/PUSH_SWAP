/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:46:12 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/26 13:56:32 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*top;
	t_stack	*undertop;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	top = *stack;
	undertop = top->next;
	top->next = undertop->next;
	if (undertop->next)
		undertop->next->prior = top;
	undertop->next = top;
	top->prior = undertop;
	*stack = undertop;
	undertop->prior = NULL;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}
