/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:07:40 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/18 12:18:02 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

t_int	ft_read_arg(const char *fmt, t_fmt_arg *arg, va_list args)
{
	t_int	i;

	i = 0;
	arg->flags = FLAG_NONE;
	while (fmt[i] && ft_read_flag (fmt[i], arg))
		i += 1;
	i += ft_read_width (fmt + i, arg);
	if (arg->width == WIDTH_ARG)
		arg->width = va_arg (args, t_int);
	i += ft_read_precision (fmt + i, arg);
	if (arg->precision == PREC_ARG)
		arg->precision = va_arg (args, t_int);
	i += ft_read_specifier (fmt[i], arg);
	ft_read_va (arg, args);
	return (i);
}

t_int	ft_vsprintf(char *buff, const char *fmt, va_list va)
{
	va_list		args;
	t_buff		b;

	va_copy (args, va);
	b.data = buff;
	b.count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt += 1;
			if (*fmt != '%')
			{
				fmt += ft_next_arg (fmt, &b, args);
				continue ;
			}
		}
		fmt += ft_putchar_buff (&b, *fmt, FALSE);
	}
	ft_putchar_buff (&b, 0, FALSE);
	va_end (args);
	return (b.count - 1);
}

t_int	ft_vprintf(const char *fmt, va_list va)
{
	char	*buff;
	t_int	len;

	len = ft_vsprintf (NULL, fmt, va);
	buff = (char *)malloc (len + 1);
	if (!buff)
		return (-1);
	ft_vsprintf (buff, fmt, va);
	write (1, buff, len);
	free (buff);
	return (len);
}

t_int	ft_sprintf(char *buff, const char *fmt, ...)
{
	va_list	args;
	t_int	len;

	va_start (args, fmt);
	len = ft_vsprintf (buff, fmt, args);
	va_end (args);
	return (len);
}

t_int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_int	len;

	va_start (args, fmt);
	len = ft_vprintf (fmt, args);
	va_end (args);
	return (len);
}
