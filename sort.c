/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:45:41 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/08 17:02:45 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	sort_three(t_stack **a)
{
	int	i1;
	int	i2;
	int	i3;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	i1 = (*a)->index;
	i2 = (*a)->next->index;
	i3 = (*a)->next->next->index;
	if (i1 > i2 && i1 < i3)
		sa(a);
	else if (i1 > i2 && i2 > i3)
	{
		sa(a);
		rra(a);
	}
	else if (i1 > i3 && i2 < i3)
		ra(a);
	else if (i1 < i2 && i1 > i3)
		rra(a);
	else if (i1 < i3 && i2 > i3)
	{
		sa(a);
		ra(a);
	}
}

void	sort_large_helper(t_stack **a, t_stack **b, t_stack *cheapest)
{
	update_position(*a);
	update_position(*b);
	lock_target(*a, *b);
	calc_cost(*a, *b);
	cheapest = find_cheap(*b);
	do_move(a, b, cheapest);
}

void	sort_large(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	int		len;
	int		len_a;

	cheapest = NULL;
	len = stack_len(*a);
	pb(a, b);
	pb(a, b);
	len -= 2;
	while (len > 3)
	{
		pb(a, b);
		len--;
	}
	len_a = stack_len(*a);
	if (len_a == 3)
		sort_three(a);
	else if (len_a == 2)
		sort_two(a);
	while (*b)
		sort_large_helper(a, b, cheapest);
	rotate_top(a);
}

void	sort(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = *a;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else
		sort_large(a, b);
}
