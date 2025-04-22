/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:45:26 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/08 16:45:27 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_func(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	head = tmp->next;
	tmp->next = NULL;
	head->next = *stack;
	*stack = head;
}

void	rra(t_stack **a)
{
	rr_func(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rr_func(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rr_func(a);
	rr_func(b);
	write(1, "rrr\n", 4);
}
