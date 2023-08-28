/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:32:34 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/28 18:18:03 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_stack(t_ps *ps)
{
	int	i;
	int	size;

	i = 0;
	size = ps->size_a;
	ps->index = ft_calloc(sizeof(int), size);
	ps->stack_copy = ft_calloc(sizeof(int), size);
	if (!ps->stack_copy || !ps->index)
		close_program(ps);
	while (i < size)
	{
		ps->stack_copy[i] = ps->stack_a[i];
		i++;
	}
}

void	sort_copy(t_ps *ps)
{
	int	i;
	int	not_sorted;
	int	size;

	i = 0;
	not_sorted = 0;
	size = ps->size_a - 1;
	while (i < size)
	{
		if (ps->stack_copy[i] > ps->stack_copy[i + 1])
		{
			ft_swap(&ps->stack_copy[i], &ps->stack_copy[i + 1]);
			not_sorted = 1;
		}
		i++;
	}
	if (not_sorted)
		sort_copy(ps);
}

void	index_stack(t_ps *ps)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ps->size_a;
	sort_copy(ps);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (ps->stack_a[i] == ps->stack_copy[j])
				ps->index[i] = j;
			j++;
		}
		i++;
	}
}

int	max_bits(t_ps *ps)
{
	int	size;
	int	max;

	size = ps->size_a;
	max = 1;
	while (size >> max != 0)
		max++;
	return (max);
}

void	radix_sort(t_ps *ps)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = max_bits(ps);
	index_stack(ps);
	free(ps->stack_a);
	ps->stack_a = ps->index;
	while (i < max)
	{
		j = 0;
		while (j < ps->final_size)
		{
			if (((ps->stack_a[0] >> i) & 1) == 1)
				rotate_a(ps, 1);
			else
				push_b(ps, 1);
			j++;
		}
		while (ps->size_b != 0)
			push_a(ps, 1);
		i++;
	}
	return ;
}
