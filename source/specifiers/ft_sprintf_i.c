/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:39:14 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/18 12:15:54 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_int	ft_sprintf_i(t_buff *buff, t_fmt_arg arg)
{
	t_int	i;
	t_int	min_width;

	i = 0;
	if (arg.i < 0)
		i += ft_putchar_buff (buff, '-', FALSE);
	else if ((arg.flags & FLAG_SIGN))
		i += ft_putchar_buff (buff, '+', FALSE);
	else if ((arg.flags & FLAG_SPACE))
		i += ft_putchar_buff (buff, ' ', FALSE);
	min_width = -1;
	if (arg.precision >= 0)
		min_width = arg.precision;
	else if (!(arg.flags & FLAG_LJUSTIFY) && (arg.flags & FLAG_ZPAD))
		min_width = arg.width - i;
	i += ft_putuint_buff (buff, (t_uint)ft_abs (arg.i), min_width, DECIMAL);
	return (i);
}
