/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:24:46 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/28 14:09:25 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_valid_instruction(t_ps *ps, char *s)
{
	if (ft_strcmp(s, "sa\n") == 0)
		swap_a(ps, 0);
	else if (ft_strcmp(s, "sb\n") == 0)
		swap_b(ps, 0);
	else if (ft_strcmp(s, "ss\n") == 0)
		swap_both(ps);
	else if (ft_strcmp(s, "sb\n") == 0)
		swap_b(ps, 0);
	else if (ft_strcmp(s, "sb\n") == 0)
		swap_b(ps, 0);
	return (1);
}

int	main(int ac, char **av)
{
	int		error_type;
	t_ps	ps;

	init_ps(&ps);
	if (ac == 1)
		return (0);
	error_type = error_management(&ps, ac, av);
	if (error_type == 0)
	{
		ft_putendl_stdout("OK");
		close_program(&ps);
	}
	else if (error_type == 2)
	{
		ft_putendl_stdout("Error");
		close_program(&ps);
	}
	return (0);
}
