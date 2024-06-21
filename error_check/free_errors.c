/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:13:25 by aokhapki          #+#    #+#             */
/*   Updated: 2024/06/21 21:24:04 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// frees all and exits the program
void	free_errors(t_stack **a, int error)
{
	t_stack	*temp;
	t_stack	*ptr;

	ptr = *a;
	while (ptr)
	{
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
	temp = NULL;
	ptr = NULL;
	*a = NULL;
	if (error == 1)
		print_error();
}
