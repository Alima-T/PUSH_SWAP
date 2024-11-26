/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:08:13 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/26 13:57:46 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replace(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = get_min_cost(*b);
	if (tmp->up_middle && tmp->focus_node->up_middle)
	{
		while (*a != tmp->focus_node && *b != tmp)
			rr(a, b);
		set_index(*a);
		set_index(*b);
	}
	else if (!(tmp->up_middle) && !(tmp->focus_node->up_middle))
	{
		while (*a != tmp->focus_node && *b != tmp)
			rrr(a, b);
		set_index(*a);
		set_index(*b);
	}
	repeat_rotate(b, tmp, 'b');
	repeat_rotate(a, tmp->focus_node, 'a');
	pa(a, b);
}

void	repeat_rotate(t_stack **stack, t_stack *focus, char c)
{
	while (focus && *stack != focus)
	{
		if (c == 'a')
		{
			if (focus && focus->up_middle)
				ra(stack);
			else if (focus && !focus->up_middle)
				rra(stack);
		}
		else if (c == 'b')
		{
			if (focus && focus->up_middle)
				rb(stack);
			else if (focus && !focus->up_middle)
				rrb(stack);
		}
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*min;
	int		size;

	size = get_size(*a);
	while (size-- > 3)
		pb(a, b);
	sort_3(a);
	while (*b)
	{
		set_index(*a);
		set_index(*b);
		set_focus(*a, *b);
		set_cost(*a, *b);
		set_cheap(*b);
		replace(a, b);
	}
	set_index(*a);
	min = get_min(*a);
	if (min->up_middle)
		while (*a != min)
			ra(a);
	else
		while (*a != min)
			rra(a);
}

int	main(int ac, char **av)
{
	char	**nums;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	nums = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
	{
		ft_putstr_fd(RED "Error! " MAG "Not enough argumnts.\n", 1);
		return (1);
	}
	else if (ac == 2)
	{
		nums = ft_split(av[1], ' ');
		init(&a, nums, ac);
	}
	else
		init(&a, av + 1, ac);
	big_sort(&a, &b);
	if (nums != NULL)
		free_all(NULL, 2, nums);
	free_all(&a, 0, NULL);
	free_all(&b, 0, NULL);
	return (0);
}
