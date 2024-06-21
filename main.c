/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 03:12:03 by aokhapki          #+#    #+#             */
/*   Updated: 2024/06/21 21:30:06 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argv == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_length(a) == 2)
			sa(&a, false);
		else if (stack_length(a) == 3)
			sort_3(&a, &b);
	}
	free_stack(&a);
	return (0);
}

/* argc (args count int) should be 2 or more, argv[0] (arg vector-array of pointers)- [0]programm's name, argv[argc-1] command-line arg
argc (ARG Count) is an int var, stores the nb of command-line args
passed by the user including the name of the program. 
So if we pass a value to a program,	the value of argc would be 2 (one for argument and one for program name)
The value of argc should be non-negative. 
argv (ARGument Vector) is an array of character pointers listing all the arguments.
If argc > 0, the array elements from argv[0] to argv[argc-1] will contain pointers to strings.
argv[0] is the name of the program ,
After that till argv[argc-1] every element is command -line arguments 
*/