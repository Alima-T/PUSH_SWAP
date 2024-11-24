/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:51:37 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/24 21:50:38 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack **stack_a, char **nums, int ac)
{
	int		i;
	long	nbr;

	i = 0;
	while ((nums[i] != NULL))
	{
		nbr = ft_atoi(nums[i]);
		if (catch_error(stack_a, nums[i], nbr) == 1)
		{
			free_all(stack_a, nums, ac);
			exit(EXIT_FAILURE);
		}
		fill_stack(stack_a, (int)nbr);
		i++;
	}
}

void	fill_stack(t_stack **stack_a, int nbr)
{
	t_stack	*node;
	t_stack	*last;

	node = malloc(sizeof(t_stack));
	if (!node)
		exit(EXIT_FAILURE);
	node->value = nbr;
	node->index = -1;
	node->previous = NULL;
	node->next = NULL;
	node->cost = -1;
	node->cheapest = false;
	node->up_middle = false;
	node->purpose_node = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = node;
		node->previous = NULL;
		return ;
	}
	last = *stack_a;
	while (!(last->next == NULL))
		last = last->next;
	last->next = node;
	node->previous = last;
}
