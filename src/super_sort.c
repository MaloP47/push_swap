/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:01:06 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/27 23:38:07 by mpeulet          ###   ########.fr       */
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

void	efficiency_loop(t_ps *ps, int i, int max)
{
	int	tmp_a;
	int	tmp_b;

	while (ps->size_b != 0)
	{
		i = -1;
		max = 2147483647;
		while (++i < ps->size_b)
		{
			tmp_a = cost(ps->size_b, i);
			tmp_b = cost(ps->size_a, ft_sup(ps, i));
			ps->stack_copy[i] = total_cost(tmp_a, tmp_b);
			if (max > ps->stack_copy[i])
			{
				max = ps->stack_copy[i];
				ps->cost_b = tmp_b;
				ps->cost_a = tmp_a;
			}
		}
		move_best_option(ps, ps->cost_a, ps->cost_b);
	}
}

void	cost_efficiency(t_ps *ps)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	ps->stack_copy = ft_calloc(sizeof(int), ps->size_b);
	if (!ps->stack_copy)
		close_program(ps);
	efficiency_loop(ps, i, max);
	free(ps->stack_copy);
}

void	super_sort(t_ps *ps)
{
	while (ps->size_a != 3)
		push_b(ps);
	sort_simple(ps);
	cost_efficiency(ps);
	order_stack_a(ps);
}
