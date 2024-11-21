/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:40:31 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/21 16:40:31 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// Function to sort a small array of 3 elements
void	sort_3(int *arr_a, int size_a) 
{
	while (!check_ascending(arr_a, size_a))/
	{
		if (arr_a[0] > arr_a[1] && arr_a[1] < arr_a[2])
			sa(arr_a); 
		else if (arr_a[0] > arr_a[1])
			sa(arr_a);
		else if (!check_ascending(arr_a, size_a))
			reverse_ra(arr_a, size_a);
	}
}

// use for small data of 5 elements
void	sort_5(int *arr_a, int *arr_b, int size_a, int size_b)
{		
	int i;

	i = 1;
	//  It moves the smallest elements from arr_a to arr_b using either ra() or reverse_ra() to position the smallest element at the top,
	while (size_a > 3)
	{
		while (arr_a[0] != i)
		{
			if (i == arr_a[size_a - 1])
				reverse_ra(arr_a, size_a);
			else
				ra(arr_a, size_a);
		}
		pb(arr_a, arr_b, &size_a, &size_b); // and then calls pb() to transfer the element to arr_b.
		i++;
	}
	sort_3(arr_a, size_a); // After reducing arr_a to 3 elements, it calls sort_3() to check_ascending those.
	pa(arr_a, arr_b, &size_a, &size_b);
	pa(arr_a, arr_b, &size_a, &size_b);
}

void	push_chunks_to_b(int *arr_a, int *arr_b, int *size_a, int *size_b)
{
	int i;
	int j;
	int chunk_size;

	j = 0;
	i = 0;
	chunk_size = calc_chunk_size(size_a) * 13 / 10;
	
	while (*size_a > 0)
	{
		if (arr_a[i] - 1 <= j)
		{
			pb(arr_a, arr_b, size_a, size_b);
			rb(arr_b, *size_b); 
			j++;
		}
		else if (arr_a[i] - 1 <= j + chunk_size)
		{
			pb(arr_a, arr_b, size_a, size_b);
			j++;
		}
		else
			ra(arr_a, *size_a);
	}
}

void	push_back_to_a(int *arr_a, int *arr_b, int *size_a, int *size_b)
{
	int i;
	int rb_count;
	int rrb_count;

	while (*size_b > 0)
	{
		rb_count = rotations_count(arr_b, *size_b - 1);
		rrb_count = (*size_b + 3) - rb_count;
		i = 0;
		if (rb_count <= rrb_count)
		{
			while (arr_b[i] - 1 != *size_b - 1)
				rb(arr_b, *size_b);
			pa(arr_a, arr_b, size_a, size_b);
		}
		else
		{
			while (arr_b[i] - 1 != *size_b - 1)
				reverse_rb(arr_b, *size_b);
			pa(arr_a, arr_b, size_a, size_b);
		}
	}
}
