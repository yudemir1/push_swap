/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:44:54 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/08 16:44:55 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		rrr(a, b);
		node->cost_a++;
		node->cost_b++;
	}
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		rr(a, b);
		node->cost_a--;
		node->cost_b--;
	}
}

void	rotate_a(t_stack **a, int *cost)
{
	while (*cost != 0)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else
		{
			rra(a);
			(*cost)++;
		}
	}
}

void	rotate_b(t_stack **b, int *cost)
{
	while (*cost != 0)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else
		{
			rrb(b);
			(*cost)++;
		}
	}
}

void	do_move(t_stack **a, t_stack **b, t_stack *cheapest)
{
	rotate_both(a, b, cheapest);
	rotate_a(a, &cheapest->cost_a);
	rotate_b(b, &cheapest->cost_b);
	pa(a, b);
}

void	rotate_top(t_stack **a)
{
	int	lowest;
	int	len;

	update_position(*a);
	lowest = find_lowest(*a);
	len = stack_len(*a);
	if (lowest > len / 2)
	{
		while (lowest < len)
		{
			rra(a);
			lowest++;
		}
	}
	else
	{
		while (lowest > 0)
		{
			ra(a);
			lowest--;
		}
	}
}
