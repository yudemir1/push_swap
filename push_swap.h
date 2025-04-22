/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:44:48 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/08 16:51:23 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

void				s_func(t_stack **stack);
void				r_func(t_stack **stack);
void				rr_func(t_stack **stack);
void				run_sorter(t_stack **a, t_stack **b);
void				checker_bonus(t_stack **a, t_stack **b);
void				ft_error(void);
int					stack_sorted(t_stack *a);
void				ft_max_int_error(char **split, int *arr);
void				parse(char **datas, t_stack **a);
int					ft_atoi_hard(const char *str, char **split, int *arr);
void				free_split(char **split);
int					is_num(char *str, int *arr);
int					count_total_args(char **datas);
void				dup_check(int *arr, int total_args);
t_stack				*new_node(int value);
void				add_back(t_stack **stack, t_stack *new);
void				fill_a(t_stack **a, int *arr, int total_args);
void				free_stack(t_stack *head);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				fill_array(t_stack *stack, int *arr);
void				sort_array(int *arr, int size);
void				assign_index(t_stack *stack, int *arr, int size);
void				index_t(t_stack *stack);
void				update_position(t_stack *stack);
void				lock_target(t_stack *a, t_stack *b);
int					find_lowest(t_stack *a);
int					find_target(t_stack *a, int index_b);
void				update_position(t_stack *stack);
void				calc_cost(t_stack *a, t_stack *b);
int					stack_len(t_stack *stack);
t_stack				*find_cheap(t_stack *b);
int					absolute(int cost);
void				rotate_b(t_stack **b, int *cost);
void				rotate_a(t_stack **a, int *cost);
void				rotate_both(t_stack **a, t_stack **b, t_stack *node);
void				do_move(t_stack **a, t_stack **b, t_stack *cheapest);
void				rotate_top(t_stack **a);
void				sort_large(t_stack **a, t_stack **b);
void				sort(t_stack **a, t_stack **b);
void				sort_two(t_stack **a);
void				sort_three(t_stack **a);
void				sort_large(t_stack **a, t_stack **b);

#endif