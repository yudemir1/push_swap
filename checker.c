/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:44:56 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/08 19:41:32 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	bonus_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	do_op(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(op, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(op, "sb\n", 3))
		sb(b);
	else if (!ft_strncmp(op, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(op, "pa\n", 3))
		pa(a, b);
	else if (!ft_strncmp(op, "pb\n", 3))
		pb(a, b);
	else if (!ft_strncmp(op, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(op, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(op, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(op, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(op, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(op, "rrr\n", 4))
		rrr(a, b);
	else
		bonus_error();
}

void	checker_bonus(t_stack **a, t_stack **b)
{
	char	*line;
	int		has_input;

	has_input = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		has_input = 1;
		do_op(line, a, b);
		free(line);
	}
	if (stack_sorted(*a) && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	else
	{
		parse(av, &a);
		index_t(a);
		checker_bonus(&a, &b);
		free_stack(a);
		free_stack(b);
	}
	return (0);
}
