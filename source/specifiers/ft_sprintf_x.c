/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:40:22 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/10 17:44:27 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_int	ft_sprintf_x(t_buff *buff, t_fmt_arg arg)
{
	const char	*base;

	base = HEX;
	if (arg.specifier == 'X')
		base = HEX_UPPER;
	return (ft_putuint_buff (buff, arg.u, arg.precision, base));
}
