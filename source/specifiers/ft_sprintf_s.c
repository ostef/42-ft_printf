/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:39:27 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/18 12:57:25 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_int	ft_sprintf_s(t_buff *buff, t_fmt_arg arg)
{
	t_bool	escape;

	escape = arg.flags & FLAG_ESCAPED;
	if (arg.precision < 0)
	{
		if (!arg.s)
			return (ft_putstr_buff (buff, "(null)", FALSE));
		return (ft_putstr_buff (buff, arg.s, escape));
	}
	if (!arg.s)
		return (ft_putstrn_buff (buff, "(null)", arg.precision, FALSE));
	return (ft_putstrn_buff (buff, arg.s, arg.precision, escape));
}
