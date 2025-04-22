/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:45:17 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/08 16:45:18 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_func(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	head = tmp->next;
	tmp->next = head->next;
	head->next = tmp;
	*stack = head;
}

void	sa(t_stack **a)
{
	s_func(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	s_func(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	s_func(a);
	s_func(b);
	write(1, "ss\n", 3);
}
