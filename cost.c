/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:45:03 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/08 16:45:04 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	calc_cost(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		len_a;
	int		len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	tmp = b;
	while (tmp)
	{
		if (tmp->pos <= len_b / 2)
			tmp->cost_b = tmp->pos;
		else
			tmp->cost_b = (tmp->pos - len_b);
		if (tmp->target_pos <= len_a / 2)
			tmp->cost_a = tmp->target_pos;
		else
			tmp->cost_a = (tmp->target_pos - len_a);
		tmp = tmp->next;
	}
}

int	absolute(int cost)
{
	if (cost < 0)
		return (-cost);
	return (cost);
}

t_stack	*find_cheap(t_stack *b)
{
	t_stack	*cheapest;
	t_stack	*tmp;
	int		cost_min;
	int		total;

	tmp = b;
	cheapest = b;
	cost_min = absolute(b->cost_a) + absolute(b->cost_b);
	while (tmp)
	{
		total = absolute(tmp->cost_a) + absolute(tmp->cost_b);
		if (total < cost_min)
		{
			cost_min = total;
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}
