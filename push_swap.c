/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:08:13 by aokhapki          #+#    #+#             */
/*   Updated: 2024/10/05 18:46:41 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int				size_a;
	int				size_b;
	int				*arr_a;
	int				*arr_b;

	arr_a = NULL;
	arr_b = 0;
	size_a = 0;
	size_b = 0;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		arr_a = get_nbs(argv, &size_a);
	else if (argc > 2)
		arr_a = get_nbs2(argc, argv, &size_a);
	if (check_error(arr_a, size_a))
		arr_b = get_arr_b(arr_b, size_a, &size_b);
	rank_nbs(arr_a, size_a);
	final_check(arr_a, arr_b, size_a, size_b);
	free(arr_b);
	free(arr_a);
}
