/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:36:20 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/27 14:01:14 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void printIntArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int	main(int ac, char **av)
{
	int		error_type;
	t_ps	ps;

	ft_memset(&ps, 0, sizeof(t_ps));
	error_type = error_management(&ps, ac, av);
	if (error_type == 0 || error_type == 2)
	{
		if (error_type == 2)
			ft_putendl_fd(ERROR, STDERR_FILENO);
		close_program(&ps);
	}
	if (main_sort(&ps))
	{
		//printIntArray(ps.stack_a, ps.final_size);
		ft_putstr_fd(SORTED, 3);
		ft_putnbr_fd(ps.move, 3);
		ft_putendl_fd(MOVES, 3);
	}
	close_program(&ps);
	return (0);
}
