/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:58:36 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/21 16:38:22 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				ft_putendl_fd("Error", 2); // TODO change to catch_error and test
				free(arr);
				exit(EXIT_FAILURE);// catch_error(arr);//// TODO change to catch_error and test
			}
			j++;
		}
		i++;
	}
	if (size == 0 || size == 1)
	{
		free(arr);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

void	catch_error(int *arr)
{
	free(arr);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	print_error(void)
{
	write (2, "Error \n", 7);
	exit(1);
}