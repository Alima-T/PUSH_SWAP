/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:51:42 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/22 21:20:57 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int				*arr_a;
	int				*arr_b;
	char 			**nums;

	arr_a = NULL;
	arr_b = NULL;
	nums =  NULL;

	if (ac < 2 || (ac == 2 && !av[1][0]))
	{
		ft_putendl_fd("Error! Arguments are not enough.\n", 1);
		return (1);
	}	
	else if (ac == 2)
	{
		nums = ft_split(av[1], ' ');
		init(&arr_a, nums, ac);
	}
	if (!(nums == NULL))
		free(nums);
	return (0);
	free(arr_b);
	free(arr_a);
}
