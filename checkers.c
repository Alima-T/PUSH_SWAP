/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:49:54 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/26 13:58:54 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief // == -__INT_MAX__ - 1 or − 2147483647−1 = -2147483648. 
/// @param nbr We can not use just -2147483648
/// @return

int	ft_is_number(char *num)
{
	int	i;

	i = 0;
	if ((num[i] == '+' || num[i] == '-') && ft_isdigit(num[i + 1]))
		i++;
	while (num[i])
	{
		while (num[i] == ' ' || num[i] == '\t')
			i++;
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_reapeated(t_stack *stack, int nbr)
{
	while (stack)
	{
		if (stack->val == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	check_error(t_stack **stack, long nbr, char *nums)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
	{
		ft_putstr_fd(RED "Error! " YEL "Number is out of integer range.\n", 2);
		return (1);
	}
	if (ft_is_reapeated(*stack, nbr))
	{
		ft_putstr_fd(RED "Error! " CYAN "Duplicate numbers found.\n", 2);
		return (1);
	}
	if (!ft_is_number(nums))
	{
		ft_putstr_fd(RED "Error! ", 2);
		ft_putstr_fd(GRN "Only integers are allowed, not other symbols.\n", 2);
		return (1);
	}
	return (0);
}
