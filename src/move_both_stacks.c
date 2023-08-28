/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_both_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:18:12 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/28 21:13:20 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_ps *push_swap, int print)
{
	swap_a(push_swap, 0);
	if (push_swap->size_b >= 2)
		swap_b(push_swap, 0);
	if (print)
		ft_putendl_stdout(SS);
	push_swap->move++;
}

void	rotate_both(t_ps *push_swap, int print)
{
	rotate_a(push_swap, 0);
	if (push_swap->size_b >= 2)
		rotate_b(push_swap, 0);
	if (print)
		ft_putendl_stdout(RR);
	push_swap->move++;
}

void	rev_rotate_both(t_ps *push_swap, int print)
{
	rev_rotate_a(push_swap, 0);
	if (push_swap->size_b >= 2)
		rev_rotate_b(push_swap, 0);
	if (print)
		ft_putendl_stdout(RRR);
	push_swap->move++;
}
