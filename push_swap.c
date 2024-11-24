/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:08:13 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/24 21:38:59 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	int		size;

	size = get_size(*stack_a);
	while (size-- > 3)
		pb(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b)
	{
		set_index(*stack_a);
		set_index(*stack_b);
		set_purpose(*stack_a, *stack_b);
		set_cost(*stack_a, *stack_b);
		set_cheapest(*stack_b);
		replace(stack_a, stack_b);
	}
	set_index(*stack_a);
	min = get_min(*stack_a);
	if (min->up_middle)
		while (*stack_a != min)
			ra(stack_a);
	else
		while (*stack_a != min)
			rra(stack_a);
}

void	replace(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = get_cheapest(*stack_b);
	if (tmp->up_middle && tmp->purpose_node->up_middle)
	{
		while (*stack_a != tmp->purpose_node && *stack_b != tmp)
			rr(stack_a, stack_b);
		set_index(*stack_a);
		set_index(*stack_b);
	}
	else if (!(tmp->up_middle) && !(tmp->purpose_node->up_middle))
	{
		while (*stack_a != tmp->purpose_node && *stack_b != tmp)
			rrr(stack_a, stack_b);
		set_index(*stack_a);
		set_index(*stack_b);
	}
	repeat_rotate(stack_b, tmp, 'b');
	repeat_rotate(stack_a, tmp->purpose_node, 'a');
	pa(stack_a, stack_b);
}

void	repeat_rotate(t_stack **stack, t_stack *purpose, char c)
{
	while (purpose && *stack != purpose)
	{
		if (c == 'a')
		{
			if (purpose && purpose->up_middle)
				ra(stack);
			else if (purpose && !purpose->up_middle)
				rra(stack);
		}
		else if (c == 'b')
		{
			if (purpose && purpose->up_middle)
				rb(stack);
			else if (purpose && !purpose->up_middle)
				rrb(stack);
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**nums;

	stack_a = NULL;
	stack_b = NULL;
	nums = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
	{
		ft_putendl_fd("Error! Arguments are not enough.\n", 1);
		return (1);
	}
	else if (ac == 2)
	{
		nums = ft_split(av[1], ' ');
		init(&stack_a, nums, ac);
	}
	else
		init(&stack_a, av + 1, ac);
	big_sort(&stack_a, &stack_b);
	if (!(nums == NULL))
		free_all(NULL, nums, 2);
	return (0);
	free_all(&stack_a, NULL, 0);
	free_all(&stack_b, NULL, 0);
}
