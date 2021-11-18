/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:47:23 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/04 16:12:52 by soumanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char *)p1)[i] == ((unsigned char *)p2)[i])
		i += 1;
	if (i == n)
		return (0);
	return (((unsigned char *)p1)[i] - ((unsigned char *)p2)[i]);
}
