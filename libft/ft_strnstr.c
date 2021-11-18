/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:17:10 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/04 16:14:46 by soumanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (!(*s2))
		return (s1);
	i = 0;
	while (i < n && s1[i])
	{
		j = 0;
		while (i + j < n && s1[i + j] && s2[j])
		{
			if (s1[i + j] != s2[j])
				break ;
			j += 1;
		}
		if (!s2[j])
			return (s1 + i);
		i += 1;
	}
	return (NULL);
}
