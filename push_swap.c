/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:45:36 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/08 17:15:57 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b, char **datas)
{
	parse(datas, &a);
	if (stack_sorted(a) && !b)
	{
		free_stack(a);
		return ;
	}
	index_t(a);
	if (stack_len(a) == 2)
		sa(&a);
	else if (stack_len(a) == 3)
		sort_three(&a);
	else
		sort_large(&a, &b);
	free_stack(a);
	free_stack(b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	else if (ac >= 2)
	{
		a = NULL;
		b = NULL;
		push_swap(a, b, av);
	}
	return (0);
}
