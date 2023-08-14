/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 22:22:16 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/10 15:41:59 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
}

int	*fill_stack(char **split, int size, int *stack)
{
	while (size >= 0)
	{
		if (ft_int_over_maxmin(ft_atol(split[size])))
		{
			ft_putendl_fd(ERR_MAXMIN, 3);
			free(stack);
			return (0);
		}
		stack[size] = ft_atol(split[size]);
		size--;
	}
	return (stack);
}

int	*parse_string(t_ps *ps, char *s)
{
	int		size;
	int		*stack;
	char	**split;

	size = 1;
	split = ft_split(s, 32);
	if (!split)
		return (0);
	while (split[size])
		size++;
	ps->size_a = size;
	stack = ft_calloc(ps->size_a, sizeof(int));
	if (!stack)
		return (0);
	size--;
	stack = fill_stack(split, size, stack);
	free_split(split, ps->size_a - 1);
	return (stack);
}

int	parse_multi(t_ps *ps, char **av)
{
	int		i;
	int		size;
	char	*s;

	size = 0;
	s = 0;
	while (av[size])
		size++;
	i = 1;
	while (i < size)
	{
		if (digit_refine(av[i]))
			return (free_string(s, 2));
		s = ft_strjoin_gnl(s, av[i]);
		if (not_digit_rel(av[i]))
			return (free_string(s, 2));
		s = ft_strjoin_gnl(s, " ");
		i++;
	}
	ps->stack_a = parse_string(ps, s);
	if (!ps->stack_a || check_duplicates(ps->stack_a, ps->size_a))
		return (free_string(s, 2));
	else if (is_stack_sorted(ps->stack_a, ps->size_a))
		return (free_string(s, 0));
	return (free_string(s, 1));
}

int	error_management(t_ps *ps, int ac, char **av)
{
	if (ac == 1 || (ac == 2 && ft_str_isdigit(av[1]) == 1))
	{
		if (ft_int_over_maxmin(ft_atol(av[1])))
			return (2);
		ft_putendl_fd(NO_PARAM, 3);
		return (0);
	}
	else if ((ac == 2 && not_digit_rel(av[1])) || av[1][0] == 0)
		return (2);
	else if (ac == 2 && ft_str_isdigit(av[1]) == 0)
	{
		if (digit_refine(av[1]))
			return (2);
		ps->stack_a = parse_string(ps, av[1]);
		if (!ps->stack_a || check_duplicates(ps->stack_a, ps->size_a))
			return (2);
		else if (is_stack_sorted(ps->stack_a, ps->size_a))
			return (0);
	}
	else if (ac > 2)
		return (parse_multi(ps, av));
	return (1);
}
