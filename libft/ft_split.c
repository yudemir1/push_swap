/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:04:50 by yudemir           #+#    #+#             */
/*   Updated: 2024/11/05 19:21:35 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numwords(char const *s, char c)
{
	int	cur;
	int	word_num;

	cur = 0;
	word_num = 0;
	while (s[cur] != '\0')
	{
		if (s[cur] != c && (s[cur + 1] == c || s[cur + 1] == '\0'))
			word_num++;
		cur++;
	}
	return (word_num);
}

static int	split_words(char **result, char const *s, char c, int word)
{
	int		start_cur;
	int		end_cur;

	end_cur = 0;
	start_cur = 0;
	while (s[end_cur] != '\0')
	{
		if (s[end_cur] == c)
			start_cur = end_cur + 1;
		else if (s[end_cur + 1] == c || s[end_cur + 1] == '\0')
		{
			result[word] = malloc(sizeof(char) * (end_cur - start_cur + 2));
			if (!result[word])
			{
				while (word > 0)
					free(result[--word]);
				return (0);
			}
			ft_strlcpy(result[word], &s[start_cur], end_cur - start_cur + 2);
			word++;
		}
		end_cur++;
	}
	result[word] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		num_words;

	if (!s)
		return (NULL);
	num_words = numwords(s, c);
	result = malloc(sizeof(char *) * (num_words + 1));
	if (!result)
		return (NULL);
	if (!split_words(result, s, c, 0))
	{
		free(result);
		return (NULL);
	}
	return (result);
}
