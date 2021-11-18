/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:17:16 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/04 18:22:52 by soumanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	long	i;

	i = 0;
	while (str[i])
		i += 1;
	while (i >= 0 && str[i] != (char)c)
		i -= 1;
	if (i == -1)
		return (NULL);
	return ((char *)str + i);
}
