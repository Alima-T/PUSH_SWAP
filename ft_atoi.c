/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 08:51:56 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/21 16:23:58 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while (*str != '\0' && ((*str >= '\t' && *str <= '\r') || *str == ' '))
		str++;
	if (*str != '\0' && (*str == '+' || *str == '-'))
	{
		if (*str++ == '-')
			sign *= -1;
	}	
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb * sign);
}
