/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:31:15 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/14 12:12:05 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ps(t_ps *ps)
{
	ps->stack_a = 0;
	ps->stack_b = 0;
	ps->size_a = 0;
	ps->size_b = 0;
	ps->index_min = 0;
	ps->index_max = 0;
	ps->min_a = 0;
	ps->max_a = 0;
	ps->move = 0;
	ps->final_size = 0;
	ps->stack_copy = 0;
	ps->index = 0;
}

void	close_program(t_ps *push_swap)
{
	if (push_swap->stack_a)
	{
		free(push_swap->stack_a);
		push_swap->stack_a = 0;
	}
	if (push_swap->stack_b)
	{
		free(push_swap->stack_b);
		push_swap->stack_b = 0;
	}
	if (push_swap->stack_copy)
	{
		free(push_swap->stack_copy);
		push_swap->stack_copy = 0;
	}
	exit(EXIT_SUCCESS);
}

int	free_string(char *s, int return_code)
{
	if (s)
		free(s);
	return (return_code);
}

int	find_max(t_ps *ps, int *stack, int size)
{
	int	i;
	int	max;

	i = 0;
	max = stack[0];
	ps->index_max = 0;
	while (i < size)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			ps->index_max = i;
		}
		i++;
	}
	return (max);
}

int	find_min(t_ps *ps, int *stack, int size)
{
	int	i;
	int	min;

	i = 0;
	min = stack[0];
	ps->index_min = 0;
	while (i < size)
	{
		if (stack[i] < min)
		{
			min = stack[i];
			ps->index_min = i;
		}
		i++;
	}
	return (min);
}
