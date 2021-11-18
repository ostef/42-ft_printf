/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:47:54 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/04 17:56:57 by soumanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	size_t			i;
	char			buffer[11];

	un = n;
	if (n < 0)
	{
		write (fd, "-", 1);
		un = -n;
	}
	else if (n == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	i = 0;
	while (un > 0)
	{
		buffer[11 - i - 1] = (un % 10) + '0';
		un /= 10;
		i += 1;
	}
	write (fd, &buffer[11 - i], i);
}
