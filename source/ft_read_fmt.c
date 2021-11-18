/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:04:22 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/18 12:19:13 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	g_fmt_specifiers[] = "cspdiuxX";
static t_fmt_func	g_fmt_funcs[] = {
	&ft_sprintf_c,
	&ft_sprintf_s,
	&ft_sprintf_p,
	&ft_sprintf_i,
	&ft_sprintf_i,
	&ft_sprintf_u,
	&ft_sprintf_x,
	&ft_sprintf_x
};
static const char	g_flag_str[] = "-+ #0e";
static t_fmt_flags	g_flag_values[] = {
	FLAG_LJUSTIFY,
	FLAG_SIGN,
	FLAG_SPACE,
	FLAG_HASH,
	FLAG_ZPAD,
	FLAG_ESCAPED
};

t_int	ft_read_uint(const char *str, t_int *out)
{
	t_int	un;
	t_int	i;

	i = 0;
	un = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		un *= 10;
		un += str[i] - '0';
		i += 1;
	}
	*out = un;
	return (i);
}

t_int	ft_read_flag(char c, t_fmt_arg *arg)
{
	t_s64		i;

	i = 0;
	while (i < (t_s64)(sizeof (g_flag_str) - 1))
	{
		if (c == g_flag_str[i])
		{
			arg->flags |= g_flag_values[i];
			return (1);
		}
		i += 1;
	}
	return (0);
}

t_int	ft_read_width(const char *fmt, t_fmt_arg *arg)
{
	t_int	i;

	i = 0;
	arg->width = WIDTH_DEFAULT;
	if (fmt[i] == '*')
	{
		arg->width = WIDTH_ARG;
		i += 1;
	}
	else if (fmt[i] >= '0' && fmt[i] <= '9')
		i += ft_read_uint (fmt + i, &arg->width);
	return (i);
}

t_int	ft_read_precision(const char *fmt, t_fmt_arg *arg)
{
	t_int	i;

	i = 0;
	arg->precision = PREC_DEFAULT;
	if (fmt[i] == '.')
	{
		i += 1;
		if (fmt[i] == '*')
		{
			arg->precision = PREC_ARG;
			i += 1;
		}
		else if (fmt[i] >= '0' && fmt[i] <= '9')
			i += ft_read_uint (fmt + i, &arg->precision);
		else
			arg->precision = 0;
	}
	return (i);
}

t_int	ft_read_specifier(char c, t_fmt_arg *arg)
{
	t_int	i;

	arg->specifier = 0;
	arg->func = NULL;
	i = 0;
	while (i < (t_int)(sizeof (g_fmt_specifiers) - 1))
	{
		if (g_fmt_specifiers[i] == c)
		{
			arg->specifier = c;
			arg->func = g_fmt_funcs[i];
			return (1);
		}
		i += 1;
	}
	return (0);
}
