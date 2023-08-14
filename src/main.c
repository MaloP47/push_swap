/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:36:20 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/14 12:36:53 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		error_type;
	t_ps	ps;

	init_ps(&ps);
	error_type = error_management(&ps, ac, av);
	if (error_type == 0 || error_type == 2)
	{
		if (error_type == 2)
			ft_putendl_fd(ERROR, STDERR_FILENO);
		close_program(&ps);
	}
	if (main_sort(&ps))
	{
		ft_putstr_fd(SORTED, 3);
		ft_putnbr_fd(ps.move, 3);
		ft_putendl_fd(MOVES, 3);
	}
	close_program(&ps);
	return (0);
}
