/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:49:54 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/24 21:51:05 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief // == -__INT_MAX__ - 1 or − 2147483647−1 = -2147483648. 
/// @param nbr We can not use just -2147483648
/// @return

int	ft_is_integer(int nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (1);
	return (0);
}

int	ft_is_duplicate(t_stack *stack, int nbr)
{
	while (stack)
	{
		if (stack->value == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_is_digit(char *s)
{
	if (!s || *s == '\0')
		return (1);
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			return (1);
		s++;
	}
	return (0);
}

int	catch_error(t_stack **stack, char *nums, long nbr)
{
	if (!ft_is_digit(nums))
	{
		ft_putendl_fd("Error! Not digits.\n", 2);
		return (1);
	}
	if (nbr > INT_MAX || nbr < INT_MIN)
	{
		ft_putendl_fd("Error! Not valid integer.\n", 2);
		return (1);
	}
	// else if(!ft_is_integer(nbr))
	// {
	// 	ft_putendl_fd("Error! Not valid integer.\n", 2);
	// 	return(1);
	// }
	if (ft_is_duplicate(*stack, nbr))
	{
		ft_putendl_fd("Error! Duplicates.\n", 2);
		return (1);
	}
	return (0);
}

void	free_all(t_stack **a, char **nums, int ac)
{
	int		i;
	t_stack	*temp;
	t_stack	*temp2;

	i = 0;
	if (ac == 2)
	{
		while (nums[i] != NULL)
		{
			free(nums[i]);
			i++;
		}
		free(nums);
		nums = NULL;
	}
	if (a == NULL || *a == NULL)
		return ;
	temp = *a;
	while (temp)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	*a = NULL;
}
