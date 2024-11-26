/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:29:41 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/26 13:48:42 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (stack == NULL)
		return ;
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
}

void	set_focus(t_stack *a, t_stack *b)
{
	int		focus_val;
	t_stack	*tmp;

	tmp = NULL;
	while (b)
	{
		tmp = a;
		focus_val = 2147483647;
		while (tmp)
		{
			if (tmp->val > b->val && tmp->val < focus_val)
			{
				b->focus_node = tmp;
				focus_val = tmp->val;
			}
			tmp = tmp->next;
		}
		if (focus_val == 2147483647)
			b->focus_node = get_min(a);
		b = b->next;
	}
}

void	set_cost(t_stack *a, t_stack *b)
{
	int	price;
	int	a_len;
	int	b_len;

	price = 0;
	a_len = get_size(a);
	b_len = get_size(b);
	while (b != NULL)
	{
		if (b->up_middle == true)
			price = b->index;
		else
			price = b_len - (b->index);
		if (b && b->focus_node && b->focus_node->up_middle == true)
			price += b->focus_node->index;
		else
			price += a_len - (b->focus_node->index);
		b->cost = price;
		b = b->next;
	}
}

void	set_cheap(t_stack *b)
{
	t_stack	*cheap;

	cheap = b;
	if (b == NULL)
		return ;
	while (b)
	{
		if (b->cost < cheap->cost)
			cheap = b;
		b = b->next;
	}
	cheap->cheap = true;
}
