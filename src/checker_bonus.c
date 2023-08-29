/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:24:46 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/29 15:08:39 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_instruction_valid(char *s)
{
	if (ft_strcmp(s, "sa\n") && ft_strcmp(s, "sb\n") && ft_strcmp(s, "ss\n")
		&& ft_strcmp(s, "pa\n") && ft_strcmp(s, "pb\n") && ft_strcmp(s, "ra\n")
		&& ft_strcmp(s, "rb\n") && ft_strcmp(s, "rr\n") && ft_strcmp(s, "rra\n")
		&& ft_strcmp(s, "rrb\n") && ft_strcmp(s, "rrr\n"))
		return (0);
	return (1);
}

void	exec_instructions1(t_ps *ps, char *s)
{
	if (ft_strcmp(s, "sa\n") == 0)
		swap_a(ps, 0);
	else if (ft_strcmp(s, "sb\n") == 0)
		swap_b(ps, 0);
	else if (ft_strcmp(s, "ss\n") == 0)
		swap_both(ps, 0);
	else if (ft_strcmp(s, "pa\n") == 0)
		push_a(ps, 0);
	else if (ft_strcmp(s, "pb\n") == 0)
		push_b(ps, 0);
}

void	exec_instructions2(t_ps *ps, char *s)
{
	if (ft_strcmp(s, "ra\n") == 0)
		rotate_a(ps, 0);
	else if (ft_strcmp(s, "rb\n") == 0)
		rotate_b(ps, 0);
	else if (ft_strcmp(s, "rr\n") == 0)
		rotate_both(ps, 0);
	else if (ft_strcmp(s, "rra\n") == 0)
		rev_rotate_a(ps, 0);
	else if (ft_strcmp(s, "rrb\n") == 0)
		rev_rotate_b(ps, 0);
	else if (ft_strcmp(s, "rrr\n") == 0)
		rev_rotate_both(ps, 0);
	else if (*s == 0 || !is_instruction_valid(s))
	{
		ft_putendl_stdout("Error");
		free(s);
		gnl(0, 1);
		close_program(ps);
	}
}

void	get_intructions(t_ps *ps)
{
	char	*line;

	line = 0;
	while (1)
	{
		line = gnl(STDIN_FILENO, 0);
		if (!line)
			break ;
		exec_instructions1(ps, line);
		exec_instructions2(ps, line);
		free(line);
	}
	gnl(0, 1);
	if (is_stack_sorted(ps->stack_a, ps->size_a) && ps->size_b == 0)
		ft_putendl_stdout("OK");
	else
		ft_putendl_stdout("KO");
	close_program(ps);
}

int	main(int ac, char **av)
{
	int		error_type;
	t_ps	ps;

	if (ac == 1)
		return (EXIT_SUCCESS);
	ft_memset(&ps, 0, sizeof(t_ps));
	error_type = error_management(&ps, ac, av);
	if (error_type == 2)
	{
		ft_putendl_fd(ERROR, STDOUT_FILENO);
		close_program(&ps);
	}
	get_intructions(&ps);
	return (EXIT_SUCCESS);
}
