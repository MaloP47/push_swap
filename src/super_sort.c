/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:01:06 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/26 23:08:46 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost(int size, int index)
{
	int	cost;

	if (index > size / 2)
		cost = size - index;
	else
		cost = -index;
	return (cost);
}

int	total_cost(int cost_a, int cost_b)
{
	int	a;
	int	b;

	a = abs_value(cost_a);
	b = abs_value(cost_b);
	if ((cost_a < 0 && cost_b < 0) || (cost_a > 0 && cost_b > 0))
	{
		if (a >= b)
			return (a);
		else
			return (b);
	}
	return (a + b);
}

void	move_best_option(t_ps *ps, int cost_a, int cost_b)
{
	while (cost_b > 0)
	{
		if (cost_a > 0)
			rev_rotate_both(ps);
		else
			rev_rotate_a(ps);
		cost_b--;
	}
	while (cost_a > 0)
		rev_rotate_b(ps);
	while (cost_b < 0)
	{
		if (cost_a < 0)
			rotate_both(ps);
		else
			rotate_a(ps);
		cost_b++;
	}
	while (cost_a < 0)
		rotate_b(ps);
	push_a(ps);
}

void	super_sort(t_ps *ps)
{
	while (ps->size_a != 3)
		push_b(ps);
	sort_simple(ps);
}
