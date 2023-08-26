/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:31:15 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/26 21:48:31 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	atol_ps(const char *str)
{
	int			i;
	int			sign;
	long		nb;

	if (!str)
		return (0);
	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32)))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i++] == 45)
			sign *= -1;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		nb = (nb * 10) + (str[i] - 48);
		if (nb * sign > INT_MAX || nb * sign < INT_MIN)
			return (-2147483649);
		i++;
	}
	return (nb * sign);
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
