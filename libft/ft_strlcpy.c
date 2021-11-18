/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:16:32 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/04 16:14:46 by soumanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	copied;

	i = 0;
	copied = 0;
	while (src[i])
	{
		if (size > 0 && i < size - 1)
		{
			dst[i] = src[i];
			copied += 1;
		}
		i += 1;
	}
	if (copied < size)
		dst[copied] = 0;
	return (i);
}
