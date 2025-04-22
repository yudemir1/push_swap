/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:54:45 by yudemir           #+#    #+#             */
/*   Updated: 2024/10/18 21:06:09 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_digit(int b, int sign)
{
	int	a;

	a = 0;
	if (b == 0)
		a = 1;
	while (b != 0)
	{
		a++;
		b = b / 10;
	}
	if (sign < 0)
		a++;
	return (a);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	long	nmb;
	int		digit;

	nmb = n;
	sign = 1;
	if (n < 0)
		sign = -1;
	nmb = nmb * sign;
	digit = ft_digit(nmb, sign);
	str = (char *)malloc(sizeof(char) * digit + 1);
	if (!str)
		return (NULL);
	str[digit] = '\0';
	while (--digit >= 0)
	{
		str[digit] = (nmb % 10) + 48;
		nmb /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
