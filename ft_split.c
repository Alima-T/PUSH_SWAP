/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:49:35 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/24 21:39:20 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_len(const char *c, char b)
{
	size_t	i;

	i = 0;
	while (*c != '\0' && *c != b)
	{
		c++;
		i++;
	}
	return (i);
}

static size_t	get_src_len(char *dest, const char *src, size_t dest_size)
{
	size_t	y;
	size_t	i;
	size_t	src_len;

	y = 0;
	i = 0;
	while (src[y] != '\0')
	{
		y++;
	}
	src_len = y;
	if (dest_size == 0)
		return (src_len);
	while (i < dest_size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (dest_size != 0)
		dest[i] = '\0';
	return (src_len);
}

static int	count_words(const char *str, char c)
{
	int	wordcount;
	int	inword;

	wordcount = 0;
	inword = 0;
	while (*str != '\0')
	{
		if (*str != c && !inword)
		{
			inword = 1;
			wordcount++;
		}
		else if (*str == c && inword)
		{
			inword = 0;
		}
		str++;
	}
	return (wordcount);
}

static int	ft_malloc_check(char **arr, size_t i)
{
	int	temp;

	if (arr[i] == NULL)
	{
		temp = i;
		while (--temp >= 0)
			free(arr[temp]);
		free(arr);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		counter;
	char	**arr;
	size_t	p;

	p = 0;
	counter = count_words(s, c);
	i = 0;
	arr = (char **)malloc(sizeof(char *) * (counter + 1));
	if (arr == NULL)
		return (NULL);
	while (i < (size_t)counter)
	{
		while (s[p] == c)
			p++;
		arr[i] = (char *)malloc(sizeof(char) * (get_len(&s[p], c) + 1));
		if (!ft_malloc_check(arr, i))
			return (NULL);
		get_src_len(arr[i], &s[p], get_len(&s[p], c) + 1);
		i++;
		while (s[p] != c && s[p])
			p++;
	}
	arr[i] = NULL;
	return (arr);
}
