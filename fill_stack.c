/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:51:37 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/26 13:59:39 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack **stack, int ac, char **nums)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp2;

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
	if (stack == NULL || *stack == NULL)
		return ;
	tmp = *stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*stack = NULL;
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

long	ft_atol(const char *str)
{
	int		i;
	int		flag;
	long	num;

	i = 0;
	flag = 1;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (flag * num);
}

void	init(t_stack **a, char **nums, int ac)
{
	int		i;
	long	nbr;

	i = 0;
	while (nums[i])
	{
		nbr = ft_atol(nums[i]);
		if (check_error(a, nbr, nums[i]) == 1)
		{
			free_all(a, ac, nums);
			exit(1);
		}
		fill_stack(a, (int)nbr);
		i++;
	}
}

void	fill_stack(t_stack **a, int nbr)
{
	t_stack	*new;
	t_stack	*end;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		exit(1);
	new->val = nbr;
	new->cost = -1;
	new->index = -1;
	new->cheap = false;
	new->up_middle = false;
	new->focus_node = NULL;
	new->prior = NULL;
	new->next = NULL;
	if (*a == NULL)
	{
		*a = new;
		new->prior = NULL;
		return ;
	}
	end = *a;
	while (end->next != NULL)
		end = end->next;
	end->next = new;
	new->prior = end;
}
