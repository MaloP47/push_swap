/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:01:06 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/27 14:03:01 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void printIntArray2(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int	ft_sup(t_ps *ps, int index)
{
	int	i;

	i = -1;
	find_min(ps, ps->stack_a, ps->size_a);
	find_max(ps, ps->stack_a, ps->size_a);
	if (ps->stack_b[index] > ps->stack_a[ps->index_max])
		return (ps->index_min);
	while (++i < ps->size_a)
		if (ps->stack_a[i] > ps->stack_b[index] && ps->stack_a[ps->index_max] > ps->stack_a[i])
			ps->index_max = i;
	return (ps->index_max);
}

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
		{
			rev_rotate_both(ps);
			/*printIntArray2(ps->stack_a, ps->size_a);
			printIntArray2(ps->stack_b, ps->size_b);*/
			cost_a--;
		}
		else
		{
			rev_rotate_a(ps, 1);
			/*printIntArray2(ps->stack_a, ps->size_a);
			printIntArray2(ps->stack_b, ps->size_b);*/
		}
		cost_b--;
	}
	while (cost_a > 0)
	{
		rev_rotate_b(ps, 1);
		/*printIntArray2(ps->stack_a, ps->size_a);
		printIntArray2(ps->stack_b, ps->size_b);*/
		cost_a--;
	}
	while (cost_b < 0)
	{
		if (cost_a < 0)
		{
			rotate_both(ps);
			/*printIntArray2(ps->stack_a, ps->size_a);
			printIntArray2(ps->stack_b, ps->size_b);*/
			cost_a++;
		}
		else
		{
			rotate_a(ps, 1);
			/*printIntArray2(ps->stack_a, ps->size_a);
			printIntArray2(ps->stack_b, ps->size_b);*/
		}
		cost_b++;
	}
	while (cost_a < 0)
	{
		rotate_b(ps, 1);
		/*printIntArray2(ps->stack_a, ps->size_a);
		printIntArray2(ps->stack_b, ps->size_b);*/
		cost_a++;
	}
	push_a(ps);
	/*printIntArray2(ps->stack_a, ps->size_a);
	printIntArray2(ps->stack_b, ps->size_b);*/
}

void	cost_efficency(t_ps *ps)
{
	int	i;
	int	tmp_a;
	int	tmp_b;
	int	cost_a;
	int	cost_b;
	int max;

	ps->stack_copy = ft_calloc(sizeof(int), ps->size_b);
	if (!ps->stack_copy)
		close_program(ps);
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
				cost_b = tmp_b;
				cost_a = tmp_a;
			}
		}
		move_best_option(ps, cost_a, cost_b);
		/*printIntArray2(ps->stack_a, ps->size_a);
		printIntArray2(ps->stack_b, ps->size_b);*/
	}
	free(ps->stack_copy);
}

void	order_stack_a(t_ps *ps)
{
	find_min(ps, ps->stack_a, ps->size_a);
	if (ps->index_min > ps->size_a / 2)
		while (ps->index_min != 0)
		{
			rev_rotate_a(ps, 1);
			find_min(ps, ps->stack_a, ps->size_a);
		}
	else
		while (ps->index_min != 0)
		{
			rotate_a(ps, 1);
			find_min(ps, ps->stack_a, ps->size_a);
		}
}

void	super_sort(t_ps *ps)
{
	while (ps->size_a != 3)
		push_b(ps);
	sort_simple(ps);
	/*printIntArray2(ps->stack_a, ps->size_a);
	printIntArray2(ps->stack_b, ps->size_b);*/
	cost_efficency(ps);
	order_stack_a(ps);
}
