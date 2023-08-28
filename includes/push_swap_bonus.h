/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:07:50 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/28 21:18:12 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

/* *** checker_bonus.c *** */

int		is_instruction_valid(char *s);
void	exec_instructions1(t_ps *ps, char *s);
void	exec_instructions2(t_ps *ps, char *s);
void	get_intructions(t_ps *ps);
int		main(int ac, char **av);

#endif