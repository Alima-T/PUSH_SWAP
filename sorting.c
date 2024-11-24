/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:45:17 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/24 21:47:31 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	int	max;

	if (stack == NULL)
		return (INT_MIN);
	max = INT_MIN;
	while (stack != NULL)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

// Function to sort a small array of 3 elements
void	sort_3(t_stack **stack)
{
	int	max;

	max = find_max(*stack);
	if ((*stack)->value == max)
		ra(stack);
	else if ((*stack)->next->value == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

bool	is_sorted(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_sorted(*stack_a))
	{
		if (get_size(*stack_a) == 2)
			sa(stack_a);
		else if (get_size(*stack_a) == 3)
			sort_3(stack_a);
		else
			push_swap(stack_a, stack_b);
	}
}
