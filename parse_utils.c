/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:45:29 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/08 18:55:31 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_hard(const char *str, char **split, int *arr)
{
	long long	res;
	int			negative;

	negative = 1;
	res = 0;
	if (ft_strlen(str) > 12)
		ft_max_int_error(split, arr);
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	if (res * negative > 2147483647 || res * negative < -2147483648)
		ft_max_int_error(split, arr);
	return (res * negative);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	is_num(char *str, int *arr)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (!(str[i + 1]) || (str[i + 1] < '0' || str[i + 1] > '9')
				|| (i > 0 && (str[i - 1] != ' ')))
			{
				free(arr);
				ft_error();
			}
		}
		else if (str[i] != ' ' && (str[i] < '0' || str[i] > '9'))
		{
			free(arr);
			ft_error();
		}
		i++;
	}
	return (1);
}

int	count_total_args(char **datas)
{
	int		i;
	int		total;
	char	**split;
	int		j;

	i = 1;
	total = 0;
	while (datas[i])
	{
		split = ft_split(datas[i], ' ');
		j = 0;
		while (split[j])
			j++;
		total += j;
		free_split(split);
		i++;
	}
	return (total);
}

void	dup_check(int *arr, int total_args)
{
	int	i;
	int	j;

	i = 0;
	while (i < total_args)
	{
		j = i + 1;
		while (j < total_args)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				ft_error();
			}
			j++;
		}
		i++;
	}
}
