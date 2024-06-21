/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_not_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:52:49 by aokhapki          #+#    #+#             */
/*   Updated: 2024/06/21 21:21:09 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Check if notnum are in the Stack, if true, it calls free_errors and exits
int	error_not_num(char *a)
{
	if (!(*a == '+' || *a == '-' || (*a >= '0' && *a <= '9')))
		return (1);
	if ((*a == '+' || *a == '-') && !(a[1] >= '0' && a[1] <= '9'))
		return (1);
	while (*++a)
	{
		if (!(*a >= '0' && *a <= '9'))
			return (1);
	}
	return (0);
}
