/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:17:29 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/18 09:31:10 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen (s);
	if (start > srclen)
		start = srclen;
	if (start + len > srclen)
		len = srclen - start;
	result = (char *)malloc (len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		result[i] = s[start + i];
		i += 1;
	}
	result[i] = 0;
	return (result);
}
