/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:40:00 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/28 18:40:10 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_minormax(t_ps *ps, int index)
{
	int	i;

	i = -1;
	find_min(ps, ps->stack_a, ps->size_a);
	find_max(ps, ps->stack_a, ps->size_a);
	if (ps->stack_b[index] > ps->stack_a[ps->index_max])
		return (ps->index_min);
	while (++i < ps->size_a)
		if (ps->stack_a[i] > ps->stack_b[index]
			&& ps->stack_a[ps->index_max] > ps->stack_a[i])
			ps->index_max = i;
	return (ps->index_max);
}

void	define_when_revrotate(t_ps *ps, int cost_a, int cost_b)
{
	while (cost_b > 0)
	{
		if (cost_a > 0)
		{
			rev_rotate_both(ps, 1);
			cost_a--;
		}
		else
			rev_rotate_a(ps, 1);
		cost_b--;
	}
	while (cost_a > 0)
	{
		rev_rotate_b(ps, 1);
		cost_a--;
	}
}

void	define_when_rev(t_ps *ps, int cost_a, int cost_b)
{
	while (cost_b < 0)
	{
		if (cost_a < 0)
		{
			rotate_both(ps, 1);
			cost_a++;
		}
		else
			rotate_a(ps, 1);
		cost_b++;
	}
	while (cost_a < 0)
	{
		rotate_b(ps, 1);
		cost_a++;
	}
}

void	move_best_option(t_ps *ps, int cost_a, int cost_b)
{
	define_when_revrotate(ps, cost_a, cost_b);
	define_when_rev(ps, cost_a, cost_b);
	push_a(ps, 1);
}

void	order_stack_a(t_ps *ps)
{
	find_min(ps, ps->stack_a, ps->size_a);
	if (ps->index_min > ps->size_a / 2)
		while (ps->index_min != 0)
			rev_rotate_a(ps, 1);
	else
		while (ps->index_min != 0)
			rotate_a(ps, 1);
}
