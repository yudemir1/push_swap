/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:45:33 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/08 16:45:34 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_position(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
}

int	find_target(t_stack *a, int index_b)
{
	t_stack	*tmp;
	int		target_index;
	int		target_pos;

	target_index = 2147483647;
	target_pos = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_index != 2147483647)
		return (target_pos);
	return (find_lowest(a));
}

int	find_lowest(t_stack *a)
{
	t_stack	*tmp;
	int		low;
	int		pos;

	tmp = a;
	low = 2147483647;
	pos = 0;
	while (tmp)
	{
		if (tmp->index < low)
		{
			low = tmp->index;
			pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (pos);
}

void	lock_target(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		target_pos;

	tmp = b;
	while (tmp)
	{
		target_pos = find_target(a, tmp->index);
		tmp->target_pos = target_pos;
		tmp = tmp->next;
	}
}
