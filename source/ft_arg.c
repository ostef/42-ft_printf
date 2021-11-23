/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:58:26 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/18 12:17:15 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

static t_s64	ft_get_len(t_fmt_arg arg, va_list va)
{
	va_list	va2;
	t_buff	null_buff;
	t_s64	len;

	null_buff.data = NULL;
	null_buff.count = 0;
	va_copy (va2, va);
	len = (*arg.func)(&null_buff, arg, va2);
	va_end (va2);
	return (len);
}

static t_s64	ft_sprint_arg(t_buff *buff, t_fmt_arg arg, va_list va)
{
	t_s64	i;
	t_s64	len;

	len = ft_get_len (arg, va);
	i = 0;
	if (!(arg.flags & FLAG_LJUSTIFY))
	{
		if ((arg.flags & FLAG_ZPAD) && arg.precision < 0)
			i += ft_putchars_buff (buff, '0', arg.width - len, FALSE);
		else
			i += ft_putchars_buff (buff, ' ', arg.width - len, FALSE);
	}
	i += (*arg.func)(buff, arg, va);
	if ((arg.flags & FLAG_LJUSTIFY))
		i += ft_putchars_buff (buff, ' ', arg.width - len, FALSE);
	return (i);
}

t_s64	ft_next_arg(t_cstr fmt, t_buff *buff, va_list va)
{
	t_fmt_arg	fmt_arg;
	t_s64		i;

	i = ft_read_arg (fmt, &fmt_arg, va);
	if (fmt_arg.func)
		ft_sprint_arg (buff, fmt_arg, va);
	return (i);
}
