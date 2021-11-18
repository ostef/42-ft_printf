/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:17:25 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/04 16:31:38 by soumanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	long	start;
	long	end;
	long	i;
	char	*result;

	start = 0;
	while (s1[start] && ft_strchr (set, s1[start]))
		start += 1;
	end = (long)ft_strlen (s1);
	if (end > 0)
		end -= 1;
	while (end > start && ft_strchr (set, s1[end]))
		end -= 1;
	result = (char *)malloc (end - start + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (i <= end - start)
	{
		result[i] = s1[start + i];
		i += 1;
	}
	result[i] = 0;
	return (result);
}
