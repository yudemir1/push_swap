/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:45:31 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/08 18:31:18 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_double_quotation(char **datas)
{
	int	i;

	i = 0;
	while (datas[i])
	{
		if (datas[i][0] == '\0')
		{
			ft_error();
		}
		i++;
	}
}

void	parse(char **datas, t_stack **a)
{
	int		i;
	int		j;
	char	**split;
	int		k;
	int		*arr;

	i = 1;
	k = 0;
	check_double_quotation(datas);
	arr = malloc(sizeof(int) * count_total_args(datas));
	while (datas[i] && is_num(datas[i], arr))
	{
		split = ft_split(datas[i], ' ');
		j = 0;
		while (split[j])
			arr[k++] = ft_atoi_hard(split[j++], split, arr);
		free_split(split);
		i++;
	}
	dup_check(arr, count_total_args(datas));
	fill_a(a, arr, count_total_args(datas));
	free(arr);
}
