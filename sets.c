/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:29:41 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/24 21:39:34 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	calc;
	int	size_a;
	int	size_b;

	calc = 0;
	size_a = get_size(stack_a);
	size_b = get_size(stack_a);
	while (stack_b != NULL)
	{
		if (stack_b->up_middle == true)
			calc = stack_b->index;
		else
			calc = size_b - (stack_b->index);
		if (stack_b && stack_b->purpose_node
			&& stack_b->purpose_node->up_middle == true)
			calc = calc + stack_b->purpose_node->index;
		else
			calc = size_a - stack_b->purpose_node->index;
		stack_b->cost = calc;
		stack_b = stack_b->next;
	}
}

void	set_cheapest(t_stack *stack_b)
{
	t_stack	*result;

	if (!stack_b)
		return ;
	result = stack_b;
	while (stack_b)
	{
		if (stack_b->cost < result->cost)
			result = stack_b;
		stack_b = stack_b->next;
	}
	result->cheapest = true;
}

void	set_index(t_stack *stack)
{
	int	i;
	int	middle;

	if (!stack)
		return ;
	i = 0;
	middle = get_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i > middle)
			stack->up_middle = false;
		else
			stack->up_middle = true;
		i++;
		stack = stack->next;
	}
	return ;
}

void	set_purpose(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		result;

	tmp = NULL;
	while (stack_b)
	{
		tmp = stack_a;
		result = INT_MAX;
		while (tmp)
		{
			if (tmp->value < result && tmp->value > stack_b->value)
			{
				stack_b->purpose_node = tmp;
				result = tmp->value;
			}
			tmp = tmp->next;
		}
		if (result == INT_MAX)
			stack_b->purpose_node = get_min(stack_a);
		stack_b = stack_b->next;
	}
}
