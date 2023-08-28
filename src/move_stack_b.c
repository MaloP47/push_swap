/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:17:29 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/28 18:17:16 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_ps *ps, int print)
{
	if (ps->size_b < 2)
		return ;
	swap_move(ps->stack_b);
	if (print)
	{
		ft_putendl_stdout(SB);
		ps->move++;
	}
}

void	push_b(t_ps *ps, int print)
{
	if (push_move(&ps->stack_a, &ps->stack_b, &ps->size_a, &ps->size_b))
	{
		if (print)
			ft_putendl_stdout(PB);
		ps->move++;
	}
}

void	rotate_b(t_ps *push_swap, int print)
{
	rotate_move(push_swap->stack_b, push_swap->size_b);
	if (print)
	{
		ft_putendl_stdout(RB);
		push_swap->move++;
	}
}

void	rev_rotate_b(t_ps *push_swap, int print)
{
	rev_rotate_move(push_swap->stack_b, push_swap->size_b);
	if (print)
	{
		ft_putendl_stdout(RRB);
		push_swap->move++;
	}
}
