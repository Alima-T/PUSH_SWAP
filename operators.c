/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:42:47 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/21 16:42:47 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//operations 1
int	sa_count = 0;
int	sb_count = 0;
int	ss_count = 0;
int	pa_count = 0;
int	pb_count = 0;
int	ra_count = 0;
int	rb_count = 0;
int	rr_count = 0;
int	rra_count = 0;
int	rrb_count = 0;
int	rrr_count = 0;
int	total_operator_count = 0;

void	sa(int *arr_a)
{
	int	buf;

	if (arr_a[0] == '\0' || arr_a[1] == '\0')
		ft_putendl_fd("Error", 2); // write(1, "Error\n", 6); check how will work
	buf = arr_a[0];
	arr_a[0] = arr_a[1];
	arr_a[1] = buf;
	write(1, "sa\n", 3);
	sa_count++;
	total_operator_count++;
}

void	sb(int *arr_b)
{
	int	buf;

	if (arr_b[0] == '\0' || arr_b[1] == '\0')
		ft_putendl_fd("Error", 2); // write(1, "Error\n", 6);
	buf = arr_b[0];
	arr_b[0] = arr_b[1];
	arr_b[1] = buf;
	write(1, "sb\n", 3);
	sb_count++;
	total_operator_count++;
}

void	sa_sb(int *arr_a, int *arr_b)
{
	int	buf;

	if (arr_a[0] == '\0' || arr_a[1] == '\0')
		ft_putendl_fd("Error", 2); // write(1, "Error\n", 6);
	buf = arr_a[0];
	arr_a[0] = arr_a[1];
	arr_a[1] = buf;
	if (arr_b[0] == '\0' || arr_b[1] == '\0')
		ft_putendl_fd("Error", 2); // write(1, "Error\n", 6);
	buf = arr_b[0];
	arr_b[0] = arr_b[1];
	arr_b[1] = buf;
	write(1, "ss\n", 3);
	ss_count++;
	total_operator_count++;
}

void	pa(int *arr_a, int *arr_b, int *size_a, int *size_b)
{
	int	i;

	i = *size_a;
	if (size_b != 0)
	{
		while (i > 0)
		{
			arr_a[i] = arr_a[i - 1];
			i--;
		}
		arr_a[0] = arr_b[0];
		(*size_a)++;
		i = 0;
		while (i < *size_b)
		{
			arr_b[i] = arr_b[i + 1];
			i++;
		}
		(*size_b)--;
	}
	write(1, "pa\n", 3);
	pa_count++;
	total_operator_count++;
}

void	pb(int *arr_a, int *arr_b, int *size_a, int *size_b)
{
	int	i;

	i = *size_b;
	if (size_a != 0)
	{
		while (i > 0)
		{
			arr_b[i] = arr_b[i - 1];
			i--;
		}
		arr_b[0] = arr_a[0];
		(*size_b)++;
		i = 0;
		while (i < *size_a)
		{
			arr_a[i] = arr_a[i + 1];
			i++;
		}
		(*size_a)--;
	}
	write(1, "pb\n", 3);
	pb_count++;
    total_operator_count++;
}

// operations 2
void	ra(int *arr_a, int size_a)
{
	int	i;
	int	buf;

	i = 1;
	buf = arr_a[0];
	while (i < size_a)
	{
		arr_a[i - 1] = arr_a[i];
		i++;
	}
	arr_a[size_a - 1] = buf;
	write(1, "ra\n", 3);
	ra_count++;
    total_operator_count++;
}

void	rb(int *arr_b, int size_b)
{
	int	i;
	int	buf;

	i = 1;
	buf = arr_b[0];
	while (i < size_b)
	{
		arr_b[i -1] = arr_b[i];
		i++;
	}
	arr_b[size_b - 1] = buf;
	write(1, "rb\n", 3);
	rb_count++;
    total_operator_count++;
}

void	ra_rb(int *arr_a, int *arr_b, int size_a, int size_b)
{
	int	i;
	int	buf;

	i = 1;
	buf = arr_a[0];
	while (i < size_a)
	{
		arr_a[i - 1] = arr_a[i];
		i++;
	}
	arr_a[size_a - 1] = buf;
	i = 1;
	buf = arr_b[0];
	while (i < size_b)
	{
		arr_b[i -1] = arr_b[i];
		i++;
	}
	arr_b[size_b - 1] = buf;
	write(1, "rr\n", 3);
	rr_count++;
    total_operator_count++;
}

// operations 3
void	reverse_ra(int *arr_a, int size_a)
{
	int	i;
	int	buf;

	i = size_a;
	buf = arr_a[size_a - 1];
	while (i > 0)
	{
		arr_a[i - 1] = arr_a[i - 2];
		i--;
	}
	arr_a[0] = buf;
	write(1, "rra\n", 4);
	rra_count++;				// Increment sa counter
    total_operator_count++;		// Increment total operator count
}

void	reverse_rb(int *arr_b, int size_b)
{
	int	i;
	int	buf;

	i = size_b;
	buf = arr_b[size_b - 1];
	while (i > 0)
	{
		arr_b[i -1] = arr_b[i - 2];
		i--;
	}
	arr_b[0] = buf;
	write(1, "rrb\n", 4);
	rrb_count++;
    total_operator_count++; 
}

void	reverse_ra_rb(int *arr_a, int *arr_b, int size_a, int size_b)
{
	int	i;
	int	buf;

	i = size_a;
	buf = arr_a[size_a - 1];
	while (i > 0)
	{
		arr_a[i - 1] = arr_a[i - 2];
		i--;
	}
	arr_a[0] = buf;
	i = size_b;
	buf = arr_b[size_b - 1];
	while (i > 0)
	{
		arr_b[i -1] = arr_b[i - 2];
		i--;
	}
	arr_b[0] = buf;
	write(1, "rrr\n", 4);
	rrr_count++;				// Increment sa counter
    total_operator_count++;		// Increment total operator count
}