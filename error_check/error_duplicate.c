/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:12:44 by aokhapki          #+#    #+#             */
/*   Updated: 2024/06/21 21:21:05 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Check if dupls are in the Stack, if True, it calls free_errors and exits
void	error_duplicate(t_stack *a)
{
	t_stack	*ptr;

	while (a)
	{
		ptr = a->next;
		while (ptr)
		{
			if (a->value == ptr->value)
				free_errors(&a, 1);
			ptr = ptr->next;
		}
		a = a->next;
	}
}
