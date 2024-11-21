/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:49:54 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/21 16:41:04 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ascending(int *arr_a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (arr_a[i] > arr_a[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_descending(int *arr_a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (arr_a[i] < arr_a[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	calc_chunk_size(int *nb)
{
	int	i;

	if (*nb < 4)
		return (1);
	i = 2;
	while (i * i < *nb)
		i++;
	if (i * i > *nb)
	{
		if ((i * i - *nb) < ((i - 1) * (i - 1) + (-*nb)))
			return (i);
	}
	return (i - 1);
}

void	final_check(int *arr_a, int *arr_b, int size_a, int size_b)
{
	if (check_ascending(arr_a, size_a))
		exit(EXIT_SUCCESS);
	else if (size_a == 2 && !check_ascending(arr_a, size_a))
		sa(arr_a);
	else if (size_a == 3 && !check_ascending(arr_a, size_a))
		sort_3(arr_a, size_a);
	else if (size_a <= 5)
		sort_5(arr_a, arr_b, size_a, size_b);
	else
	{
		push_chunks_to_b(arr_a, arr_b, &size_a, &size_b);
		push_back_to_a(arr_a, arr_b, &size_a, &size_b);
	}
}
