/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:46:12 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/24 21:51:47 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack *top;
	t_stack *second;

	if (!stack || !((*stack)->next == NULL) || !(*stack == NULL))
		return ;
	top = *stack;
	second = (*stack)->next;
	top->next = second->next;
	if (second->next)
		second->next->previous = top;
	second->previous = NULL;
	top->previous = second;
	second->next = top;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa\n", 1);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss\n", 1);
}
