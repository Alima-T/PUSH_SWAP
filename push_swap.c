/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:08:13 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/23 18:15:21 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	init(t_stack **stack_a, char **nums, int ac)
{
	int i;
	long nbr;
	
	i = 0;
	while(!(nums[i] == NULL))
	{
		nbr = ft_atoi(nums[i]);
		if(check_error(stack_a, nums[i], nbr) == 1)
		{
			
			ft_putendl_fd("Error! Duplicates or invalid arguments.\n", 2); 
			free_all(stack_a, nums, ac);
			exit(EXIT_FAILURE);
		}
		fill_stack(stack_a, (int)nbr);
		i++;
	}
}

void fill_stack(t_stack **stack_a, int nbr)
{
	t_stack *node;
	t_stack *last;

	if(!(node = malloc(sizeof(t_stack))))
		exit(EXIT_FAILURE);
	node->value = nbr;
	node->i = -1;
	node->previous = NULL;
	node->next = NULL;
	if(*stack_a == NULL)
	{
		*stack_a = node;
		node->previous = NULL;
		return ;
	}
	last = *stack_a;
	while(!(last->next == NULL))
		last = last->next;
	last->next = node;
	node->previous = last; 
}
