/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:47:30 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/08 02:46:46 by soumanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int		dir;
	long	i;
	long	end;

	if ((!dst && !src) || n == 0)
		return (dst);
	dir = (dst < src) * 2 - 1;
	i = (dst >= src) * (n - 1);
	end = (dst < src) * n - (dst >= src);
	while (i != end)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i += dir;
	}
	return (dst);
}
