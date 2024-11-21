/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:08:39 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/21 16:41:53 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define NUM_ELEMENTS 500
# define MAX_VALUE 10000

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	size;
}		t_stack;

// parsing
int		*get_nbs(char **argv, int *size_a);
int		*get_nbs2(int argc, char **argv, int *size_a);

// sorting
void	rank_nbs(int *arr_a, int size_a);
void	map_to_ranks(int *arr_a, int *sorted_arr, int size_a);
void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

// checkers
int		check_error(int *arr, int size);
int		*get_arr_b(int *arr_b, int size_a, int *size_b);
int		check_ascending(int *arr_a, int size_a);
int		check_descending(int *arr_a, int size_a);
void	final_check(int *arr_a, int *arr_b, int size_a, int size_b);
void	catch_error(int *arr);

// operations
void	sa(int *arr_a);
void	sb(int *arr_b);
void	sa_sb(int *arr_a, int *arr_b);
void	pb(int *arr_a, int *arr_b, int *size_a, int *size_b);
void	pa(int *arr_a, int *arr_b, int *size_a, int *size_b);
void	ra(int *arr_a, int size_a);
void	rb(int *arr_a, int size_b);
void	ra_rb(int *arr_a, int *arr_b, int size_a, int size_b);
void	reverse_ra(int *arr_a, int size_a);
void	reverse_rb(int *arr_b, int size_b);
void	reverse_ra_rb(int *arr_a, int *arr_b, int size_a, int size_b);

// void	get_max_min(int *arr, int size, int *min, int *max);
int		calc_chunk_size(int *nbr);
int		rotations_count(int *arr_a, int size_a);

// sorting
void	sort_3(int *arr_a, int size_a);
void	sort_5(int *arr_a, int *arr_b, int size_a, int size_b);
void	push_chunks_to_b(int *arr_a, int *arr_b, int *size_a, int *size_b);
void	push_back_to_a(int *arr_a, int *arr_b, int *size_a, int *size_b);

#endif