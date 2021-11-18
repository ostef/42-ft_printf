/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:47:12 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/04 16:10:43 by soumanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static long	ft_itoa_len(int n)
{
	unsigned int	un;
	long			len;

	if (n == 0)
		return (1);
	len = 0;
	un = n;
	if (n < 0)
	{
		len += 1;
		un = -n;
	}
	while (un > 0)
	{
		len += 1;
		un /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	un;
	long			i;
	long			len;
	char			*result;

	len = ft_itoa_len (n);
	result = (char *)malloc (len + 1);
	if (!result)
		return (NULL);
	un = n;
	if (n < 0)
	{
		result[0] = '-';
		un = -n;
	}
	i = len - 1;
	while (i >= (n < 0))
	{
		result[i] = (un % 10) + '0';
		un /= 10;
		i -= 1;
	}
	result[len] = 0;
	return (result);
}
