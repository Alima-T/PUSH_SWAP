/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:40:53 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/21 16:40:53 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	rank_nbs(int *arr_a, int size_a)
{
	int	*sorted_arr;
	int	i;
	int	j;	// Index for comparing elements during sorting
	int	temp;

	sorted_arr = malloc(sizeof(int) * size_a); // Copy elements from arr_a to sorted_arr
	i = -1;
	while (++i < size_a)
		sorted_arr[i] = arr_a[i];
	// Sort the sorted_arr using a simple bubble check_ascending algorithm
	i = -1;
	while (++i < size_a - 1)
	{
		j = i;
		while (++j < size_a)
		{
			// Swap elements if they are out of order
			if (sorted_arr[i] > sorted_arr[j])
			{
				temp = sorted_arr[i];
				sorted_arr[i] = sorted_arr[j];
				sorted_arr[j] = temp;
			}
		}
	}
	// Call map_to_ranks to map the original numbers to their ranks
	map_to_ranks(arr_a, sorted_arr, size_a);
}

void	map_to_ranks(int *arr_a, int *sorted_arr, int size_a)
{
	int i; // Index for iterating through arr_a
	int j; // Index for finding the rank of elements
	// Map each element in arr_a to its rank based on sorted_arr	
	i = -1;
	while (++i < size_a)
	{
		j = -1;
		while (++j < size_a)
		{
			// Find the rank of the current element in arr_a
			if (arr_a[i] == sorted_arr[j])
			{
				// Update arr_a with the rank (index + 1)
				arr_a[i] = j + 1;
				break ;
			}
		}
	}
	free(sorted_arr);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
