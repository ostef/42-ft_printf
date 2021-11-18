/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:46:38 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/07 23:20:09 by soumanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long	un;
	int				sign;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str += 1;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '+') * 2 - 1;
		str += 1;
	}
	un = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		un *= 10;
		un += *str - '0';
		str += 1;
	}
	return ((int)(sign * un));
}
