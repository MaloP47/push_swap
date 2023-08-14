/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:47:37 by mpeulet           #+#    #+#             */
/*   Updated: 2023/07/18 23:51:27 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_move(int *stack)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	push_reduce_stack_from(int **stack_from, int *size_from)
{
	int		i;
	int		*tmp;

	i = 0;
	tmp = ft_calloc(*size_from, sizeof(int));
	if (!tmp)
		return ;
	while (i < *size_from -1)
	{
		tmp[i] = (*stack_from)[i + 1];
		i++;
	}
	free(*stack_from);
	*stack_from = tmp;
	(*size_from)--;
}

int	push_move(int **stck_from, int **stck_to, int *size_from, int *size_to)
{
	int		i;
	int		*tmp;

	if (*size_from == 0)
		return (0);
	i = 0;
	tmp = ft_calloc(*size_to + 1, sizeof(int));
	if (!tmp)
		return (0);
	tmp[0] = (*stck_from)[0];
	while (i < *size_to)
	{
		tmp[i + 1] = (*stck_to)[i];
		i++;
	}
	free(*stck_to);
	*stck_to = tmp;
	(*size_to)++;
	push_reduce_stack_from(stck_from, size_from);
	return (1);
}

void	rotate_move(int *stack, int size)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack[0];
	while (++i < size)
		stack[i - 1] = stack[i];
	stack[size - 1] = tmp;
}

void	rev_rotate_move(int *stack, int size)
{
	int	i;
	int	tmp;

	i = size;
	tmp = stack[size - 1];
	while (--i > 0)
		stack[i] = stack[i - 1];
	stack[0] = tmp;
}
