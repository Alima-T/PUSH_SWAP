/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:30:13 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/26 12:53:58 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(t_stack *stack)
{
	int		size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*get_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->val < min->val)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*get_min_cost(t_stack *b)
{
	if (!b)
		return (NULL);
	while (b)
	{
		if (b->cheap)
			return (b);
		b = b->next;
	}
	return (NULL);
}
