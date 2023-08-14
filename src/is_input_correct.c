/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_input_correct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:01:42 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/10 15:39:36 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	not_digit_rel(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((av[i] >= 33 && av[i] <= 42) || (av[i] >= 58 && av[i] <= 126)
			|| av[i] == 44 || av[i] == 46 || av[i] == 47)
		{
			ft_putendl_fd(ERR_WRONG, 3);
			return (1);
		}
		i++;
	}
	return (0);
}

int	min_or_max(int *stack, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (ft_int_over_maxmin(stack[i]))
		{
			ft_putendl_fd(ERR_MAXMIN, 3);
			return (1);
		}
	}
	return (0);
}

int	check_duplicates(int *stack, int size)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
			{
				ft_putendl_fd(ERR_DUPLI, 3);
				return (1);
			}
			j++;
		}
	}
	return (0);
}

int	is_stack_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (++i < size)
	{
		if (stack[i] < stack[i - 1])
			return (0);
	}
	ft_putendl_fd(SUCC_SORT, 3);
	return (1);
}

int	digit_refine(char *s)
{
	int	i;

	i = 0;
	while (s[i] && ft_iswhitespace(s[i]))
		i++;
	if (s[i] == 0)
		return (1);
	while (s[i])
	{
		while (s[i] && ft_iswhitespace(s[i]))
			i++;
		if (s[i] && ft_is_sign(s[i]))
		{
			if ((i == 0 || ft_iswhitespace(s[i - 1])) && ft_isdigit(s[i + 1]))
				i++;
			else
				return (1);
		}
		if (s[i] && !ft_isdigit(s[i]))
			return (1);
		while (s[i] && ft_isdigit(s[i]))
			i++;
	}
	return (0);
}
