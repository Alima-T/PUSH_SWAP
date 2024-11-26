/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:48:34 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/26 17:23:06 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prior = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->prior = tmp;
	*dest = tmp;
}

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
