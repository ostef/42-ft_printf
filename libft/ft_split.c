/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:45:07 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/06 16:20:51 by soumanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_dup(char **split, long i, const char *s, size_t len)
{
	size_t	j;

	split[i] = (char *)malloc (len + 1);
	if (!split[i])
	{
		while (i >= 0)
		{
			free (split[i]);
			i -= 1;
		}
		free (split);
		return (0);
	}
	j = 0;
	while (j < len)
	{
		split[i][j] = s[j];
		j += 1;
	}
	split[i][j] = 0;
	return (1);
}

static int	ft_count_words(const char *s, char c)
{
	size_t	start;
	size_t	end;
	int		result;

	result = 0;
	start = 0;
	end = 0;
	while (s[end])
	{
		if (s[end] == c)
		{
			if (end > start)
				result += 1;
			start = end + 1;
		}
		end += 1;
	}
	if (end > start)
		result += 1;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	size_t	start;
	size_t	end;
	long	i;
	char	**result;

	result = (char **)malloc (sizeof (char *) * (ft_count_words (s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	end = 0;
	while (s[end])
	{
		if (s[end] == c)
		{
			if (end > start && !ft_dup (result, i++, s + start, end - start))
				return (NULL);
			start = end + 1;
		}
		end += 1;
	}
	if (end > start && !ft_dup (result, i++, s + start, end - start))
		return (NULL);
	result[i] = NULL;
	return (result);
}
