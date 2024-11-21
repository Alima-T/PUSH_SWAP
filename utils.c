/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:40:18 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/21 16:40:18 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//  по возрастанию
int	check_ascending(int *arr_a, int size_a)
{
	int i;

	i = 0;
	while (i < size_a - 1)
	{
		// Если текущий элемент больше следующего, массив не отсортирован
		if (arr_a[i] > arr_a[i + 1])
		{
			return (0); // Вернуть 0, если массив не отсортирован
		}
		i++;
	}
	return (1); // Вернуть 1, если массив отсортирован
}

// по убыванию
int	check_descending(int *arr_a, int size_a)
{
	int i;

	i = 0;
	while (i < size_a - 1)
	{
		if (arr_a[i] < arr_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	calc_chunk_size(int *nb)
{
	int i;
	if (*nb < 4)
		return (1);
	i = 2;
	while (i * i < *nb)
		i++;
	if (i * i > *nb)
	{
		if ((i * i - *nb) < ((i - 1) * (i - 1) + (-*nb)))
			return (i);
	}
	return (i - 1);
}

int	rotations_count(int *arr_a, int size_a)
{
	int i;

	i = 0;
	while (i <= size_a - 1 && arr_a[i] - 1 != size_a) // while (i < size_a && arr_a[i] != size_a+1)
		i++; 
	return (i);
}
/*
**Choosing the Best Fit**:
   - By evaluating both \( i^2 \) and \( (i - 1)^2 \),
	you can compare which squared value is closer to \( *nb \).
   This allows for an effective approximation by choosing the integer whose square provides a better fit.
   **Выбор наилучшего значения**:
   - Оценив как \( i^2 \), так и \( (i - 1)^2 \), можно сравнить, kакое из квадратных значений ближе к \( *nb \).
   Это позволяет эффективно выбирать целое число, 	квадрат которого лучше всего приближает значение \( *nb \).
   Предположим,	вам нужно аппроксимировать \( *nb = 20 \) и выбрать целое число \( i \),
	такое что \( i^2 \) ближе к \( 20 \):

- **Проверка для \( i = 4 \)**:
  - \( i^2 = 16 \)
  - Разница: \( 20 - 16 = 4 \)

- **Проверка для \( i = 5 \)**:
  - \( i^2 = 25 \)
  - Разница: \( 25 - 20 = 5 \)

В этом случае:
- \( 16 \) (для \( i = 4 \)) ближе к \( 20 \), чем \( 25 \) (для \( i = 5 \)).
- Поэтому выбирается \( i = 4 \), так как \( 16 \) ближе к \( 20 \),
	чем \( 25 \).
*/