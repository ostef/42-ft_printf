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

#include "ft_printf.h"

void	ft_read_va(t_fmt_arg *arg, va_list args)
{
	if (!arg->specifier)
		return ;
	if (arg->specifier == 'u' || arg->specifier == 'x'
		|| arg->specifier == 'X')
		arg->u = va_arg (args, t_uint);
	else if (arg->specifier == 's' || arg->specifier == 'p')
		arg->p = va_arg (args, void *);
	else
		arg->i = va_arg (args, t_int);
}

static t_int	ft_sprintf_hash(t_buff *buff, t_fmt_arg arg)
{
	if (arg.specifier == 'p')
		return (ft_putstr_buff (buff, "0x", FALSE));
	if (arg.specifier == 'x' && (arg.flags & FLAG_HASH) && arg.u != 0)
		return (ft_putstr_buff (buff, "0x", FALSE));
	if (arg.specifier == 'X' && (arg.flags & FLAG_HASH) && arg.u != 0)
		return (ft_putstr_buff (buff, "0X", FALSE));
	return (0);
}

t_int	ft_next_arg(const char *fmt, t_buff *buff, va_list args)
{
	t_fmt_arg	fmt_arg;
	t_int		i;

	i = 0;
	i += ft_read_arg (fmt, &fmt_arg, args);
	if (fmt_arg.func)
		ft_sprintf_with_flags (buff, fmt_arg);
	return (i);
}

t_int	ft_sprintf_with_flags(t_buff *buff, t_fmt_arg arg)
{
	t_int	i;
	t_int	len;
	t_buff	null_buff;

	null_buff.data = NULL;
	null_buff.count = 0;
	len = (*arg.func)(&null_buff, arg);
	len += ft_sprintf_hash (&null_buff, arg);
	i = 0;
	if ((arg.flags & FLAG_ZPAD))
		i += ft_sprintf_hash (buff, arg);
	if (!(arg.flags & FLAG_LJUSTIFY))
	{
		if ((arg.flags & FLAG_ZPAD) && arg.precision < 0)
			i += ft_putchars_buff (buff, '0', arg.width - len, FALSE);
		else
			i += ft_putchars_buff (buff, ' ', arg.width - len, FALSE);
	}
	if (!(arg.flags & FLAG_ZPAD))
		i += ft_sprintf_hash (buff, arg);
	i += (*arg.func)(buff, arg);
	if ((arg.flags & FLAG_LJUSTIFY))
		i += ft_putchars_buff (buff, ' ', arg.width - len, FALSE);
	return (i);
}
