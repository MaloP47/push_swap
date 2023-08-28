/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:16:45 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/28 18:17:16 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_ps *ps, int print)
{
	if (ps->size_a < 2)
		return ;
	swap_move(ps->stack_a);
	if (print)
	{
		ft_putendl_stdout(SA);
		ps->min_a = find_min(ps, ps->stack_a, ps->size_a);
		ps->max_a = find_max(ps, ps->stack_a, ps->size_a);
		ps->move++;
	}
}

void	push_a(t_ps *ps, int print)
{
	if (push_move(&ps->stack_b, &ps->stack_a, &ps->size_b, &ps->size_a))
	{
		if (print)
			ft_putendl_stdout(PA);
		ps->min_a = find_min(ps, ps->stack_a, ps->size_a);
		ps->max_a = find_max(ps, ps->stack_a, ps->size_a);
		ps->move++;
	}
}

void	rotate_a(t_ps *ps, int print)
{
	rotate_move(ps->stack_a, ps->size_a);
	if (print)
	{
		ft_putendl_stdout(RA);
		ps->min_a = find_min(ps, ps->stack_a, ps->size_a);
		ps->max_a = find_max(ps, ps->stack_a, ps->size_a);
		ps->move++;
	}
}

void	rev_rotate_a(t_ps *ps, int print)
{
	rev_rotate_move(ps->stack_a, ps->size_a);
	if (print)
	{
		ft_putendl_stdout(RRA);
		ps->min_a = find_min(ps, ps->stack_a, ps->size_a);
		ps->max_a = find_max(ps, ps->stack_a, ps->size_a);
		ps->move++;
	}
}
