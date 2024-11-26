/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:45:17 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/26 13:50:47 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *a)
{
	int	max;

	max = INT_MIN;
	while (a != NULL)
	{
		if (a->val > max)
			max = a->val;
		a = a->next;
	}
	return (max);
}

void	sort_3(t_stack **a)
{
	int	max_num;

	max_num = find_max(*a);
	if ((*a)->val == max_num)
		ra(a);
	else if ((*a)->next->val == max_num)
		rra(a);
	if ((*a)->val > (*a)->next->val)
		sa(a);
}

bool	is_sorted(t_stack *a)
{
	while (a->next != NULL)
	{
		if (a->val > a->next->val)
			return (false);
		a = a->next;
	}
	return (true);
}

void	big_sort(t_stack **a, t_stack **b)
{
	if (!is_sorted(*a))
	{
		if (get_size(*a) == 2)
			sa(a);
		else if (get_size(*a) == 3)
			sort_3(a);
		else
			push_swap(a, b);
	}
}
