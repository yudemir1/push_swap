/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:45:20 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/08 16:45:21 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_func(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	head = tmp->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	*stack = head;
	tmp->next->next = NULL;
}

void	ra(t_stack **a)
{
	r_func(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	r_func(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	r_func(a);
	r_func(b);
	write(1, "rr\n", 3);
}
