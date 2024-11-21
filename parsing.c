/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:06:53 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/21 16:43:05 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_nbs(char **argv, int *size_a)
{
	int		i;
	int		*parsed_nbs;
	char	**stacks;
	t_stack	stack_size;

	stacks = ft_split(argv[1], ' ');
	i = 0;
	while (stacks[i])
		i++;
	stack_size.size = i;
	parsed_nbs = malloc(sizeof(int) * (i - 1));
	catch_error(parsed_nbs);
	i = -1;
	while (++i < stack_size.size)
		parsed_nbs[i] = ft_atoi(stacks[i]);
	i = -1;
	while (stacks[++i])
		free(stacks[i]);
	free(stacks);
	*size_a = stack_size.size;
	return (parsed_nbs);
}

int	*get_nbs2(int argc, char **argv, int *size_a)
{
	int		i;
	int		*parsed_nbs;
	t_stack	stack_size;

	i = 0;
	stack_size.size = argc - 1;
	parsed_nbs = malloc(sizeof(int) * (stack_size.size));
	i = 0;
	while (i < stack_size.size)
	{
		if ((!argv[i + 1][1] && (argv[i + 1][0] == '-'))
			|| *argv[i + 1] == ' ' || *argv[i + 1] == '\t')
		// if (*argv[i + 1] == ' ' || *argv[i + 1] == '\t'
		// 	|| (argv[i + 1][0] == '-' && argv[i + 1][1] == '\0'))
		{
			ft_putendl_fd("Error", 2);
			free(parsed_nbs);
			exit(EXIT_FAILURE);
			// catch_error(parsed_nbs);//// TODO change to catch_error
		}
		parsed_nbs[i] = ft_atoi(argv[i + 1]);
			// TODO parsed_nbs[i++] = ft_atoi(argv[i + 1]);
			// Convert each argument to an integer and store it.
		i++;
	}
	*size_a = stack_size.size;
		// Set the integer pointed to by size_a to the number of elements.
	return (parsed_nbs);       // Return the array of integers.
}
