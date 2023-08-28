/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:31:25 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/28 18:40:12 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "messages.h"
# include "libft.h"

typedef struct s_pushswap
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
	int		min_a;
	int		max_a;
	int		cost_a;
	int		cost_b;
	int		index_min;
	int		index_max;
	int		move;
	int		final_size;
	int		*stack_copy;
	int		*index;
}		t_ps;

/* *** is_input_correct.c *** */

int		not_digit_rel(char *av);
int		min_or_max(int *stack, int size);
int		check_duplicates(int *pile, int size);
int		is_stack_sorted(int *stack, int size);
int		digit_refine(char *s);

/* *** movements.c *** */

void	swap_move(int *stack);
void	push_reduce_stack_from(int **stack_from, int *size_from);
int		push_move(int **stck_from, int **stck_to, int *size_from, int *size_to);
void	rotate_move(int *stack, int size);
void	rev_rotate_move(int *stack, int size);

/* *** move_stack_a.c *** */

void	swap_a(t_ps *push_swap, int print);
void	push_a(t_ps *push_swap, int print);
void	rotate_a(t_ps *push_swap, int print);
void	rev_rotate_a(t_ps *push_swap, int print);

/* *** move_stack_b.c *** */

void	swap_b(t_ps *push_swap, int print);
void	push_b(t_ps *push_swap, int print);
void	rotate_b(t_ps *push_swap, int print);
void	rev_rotate_b(t_ps *push_swap, int print);

/* *** move_both_stacks.c *** */

void	swap_both(t_ps *push_swap, int print);
void	rotate_both(t_ps *push_swap, int print);
void	rev_rotate_both(t_ps *push_swap, int print);

/* *** parse_string.c *** */

void	free_split(char **split, int i);
int		*fill_stack(char **split, int size, int *stack);
int		*parse_string(t_ps *ps, char *s);
int		parse_multi(t_ps *ps, char **av);
int		error_management(t_ps *ps, int ac, char **av);

/* *** radix_sort.c *** */

void	copy_stack(t_ps *ps);
void	sort_copy(t_ps *ps);
void	index_stack(t_ps *ps);
int		max_bits(t_ps *ps);
void	radix_sort(t_ps *ps);

/* *** sort.c *** */

void	sort_simple(t_ps *ps);
void	another_simple(t_ps *ps);
int		main_sort(t_ps *ps);

/* *** super_sort_utilc.c *** */

int		index_minormax(t_ps *ps, int index);
void	define_when_revrotate(t_ps *ps, int cost_a, int cost_b);
void	define_when_rev(t_ps *ps, int cost_a, int cost_b);
void	move_best_option(t_ps *ps, int cost_a, int cost_b);
void	order_stack_a(t_ps *ps);

/* *** super_sort.c *** */

int		cost(int size, int index);
int		total_cost(int cost_a, int cost_b);
void	efficiency_loop(t_ps *ps, int i, int max);
void	cost_efficiency(t_ps *ps);
void	super_sort(t_ps *ps);

/* *** utils.c *** */

long	atol_ps(const char *str);
void	close_program(t_ps *push_swap);
int		free_string(char *s, int return_code);
int		find_max(t_ps *ps, int *stack, int size);
int		find_min(t_ps *ps, int *stack, int size);

#endif