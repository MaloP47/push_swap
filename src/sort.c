/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:52:13 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/14 12:36:17 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_ps *ps)
{
	ps->min_a = find_min(ps, ps->stack_a, ps->size_a);
	ps->max_a = find_max(ps, ps->stack_a, ps->size_a);
	if (ps->index_max == 0)
		rotate_a(ps, 1);
	else if (ps->index_max == 1)
		rev_rotate_a(ps, 1);
	if (STACK_A[0] > STACK_A[1])
		swap_a(ps, 1);
}

void	another_simple(t_ps *ps)
{
	int	size_a;

	size_a = ps->size_a;
	while (size_a > 3)
	{
		while (ps->index_min > 0)
		{
			if (ps->index_min == ps->size_a - 1
				|| ps->index_min == ps->size_a - 2)
				rev_rotate_a(ps, 1);
			else
				rotate_a(ps, 1);
		}
		push_b(ps);
		size_a--;
	}
	sort_simple(ps);
	push_a(ps);
	if (FINAL_SIZE == 5)
		push_a(ps);
}

int	main_sort(t_ps *ps)
{
	ps->min_a = find_min(ps, ps->stack_a, ps->size_a);
	ps->max_a = find_max(ps, ps->stack_a, ps->size_a);
	FINAL_SIZE = ps->size_a;
	if (FINAL_SIZE == 2)
		swap_a(ps, 1);
	else if (FINAL_SIZE <= 3)
		sort_simple(ps);
	else if (FINAL_SIZE == 4 || FINAL_SIZE == 5)
		another_simple(ps);
	else
	{
		copy_stack(ps);
		radix_sort(ps);
	}
	return (1);
}
