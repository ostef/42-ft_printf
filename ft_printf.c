#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

static const char		g_fmt_specifiers[] = "cspdiuxX";
static const t_fmt_func	g_fmt_funcs[] = {
	&ft_sprintf_c,
	&ft_sprintf_s,
	&ft_sprintf_p,
	&ft_sprintf_i,
	&ft_sprintf_i,
	&ft_sprintf_u,
	&ft_sprintf_x,
	&ft_sprintf_x,
};
static const char		*g_fmt_lengths[] = { "hh", "h", "l", "ll", "j", "z" };
static const char		*g_digits = "0123456789abcdef";
/*static const char		*g_upper_digits = "0123456789ABCDEF";*/

static t_int	ft_read_flag(char c, t_fmt_arg *arg)
{
	arg->flags = 0;
	if (c == '-')
		arg.flags |= FMT_LJUSTIFY;
	else if (c == '+')
		arg.flags |= FMT_SIGN;
	else if (c == '#')
		arg.flags |= FMT_HASH;
	else if (c == '0')
		arg.flags |= FMT_ZPAD;
	else
		return (0);
	return (1);
}

static t_int	ft_read_width(const char *fmt, t_fmt_arg *arg)
{
	t_int	i;

	i = 0;
	arg->width = 0;
	if (fmt[i] == '*')
	{
		arg->width = -1;
		i += 1;
	}
	else if (fmt[i] >= '0' && fmt[i] <= '9')
		i += ft_read_number (fmt + i, &arg->width);
	return (i);
}

static t_int	ft_read_precision(const char *fmt, t_fmt_arg *arg)
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
			i += ft_read_number (fmt + i, &arg->precision);
		else
			arg->precision = 0;
	}
	return (i);
}

static t_int	ft_read_length(const char *fmt, t_fmt_arg *arg)
{
	t_int	i;

	arg->length = LENGTH_NONE;
	i = 0;
	while (i < LENGTH_COUNT)
	{
		if (ft_strcpy (fmt, g_fmt_lengths[i]) == 0)
		{
			arg->length = i + 1;
			return (ft_strlen (g_fmt_lengths[i]));
		}
		i += 1;
	}
	return (0);
}

static t_int	ft_read_specifier(char c, t_fmt_arg *arg)
{
	t_int	i;

	arg->specifier = 0;
	arg->func = NULL;
	i = 0;
	while (i < ft_strlen (g_fmt_specifiers))
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

static void	ft_read_value(t_fmt_arg *arg, va_list args)
{
	t_bool	is_unsigned;
	t_bool	is_int;

	if (!arg.specifier)
		return ;
	is_unsigned = arg->specifier == 'u'
		|| arg->specifier == 'x' || arg->specifier == 'X';
	is_int = !(arg->specifier == 's' || arg->specifier == 'p');
	if (!is_int)
		arg->p = va_arg (args, void *);
	else if (is_unsigned)
		arg->as_ulong = va_arg (args, unsigned long);
	else
		arg->as_long = va_arg (args, long);
	if (is_unsigned)
	{
		if (arg->length == LENGTH_NONE)
			arg->as_ulong = (t_u32)arg->as_ulong;
		else if (arg->length == LENGTH_HH)
			arg->as_ulong = (t_u8)arg->as_ulong;
		else if (arg->length == LENGTH_H)
			arg->as_ulong = (t_u16)arg->as_ulong;
	}
	else if (is_int)
	{
		if (arg->length == LENGTH_NONE)
			arg->as_long = (t_s32)arg->as_ulong;
		else if (arg->length == LENGTH_HH)
			arg->as_long = (t_s8)arg->as_ulong;
		else if (arg->length == LENGTH_H)
			arg->as_long = (t_s16)arg->as_ulong;
	}
}

static t_int	ft_next_arg(const char *fmt, t_fmt_arg *arg, va_list args)
{
	t_int	i;

	i = 0;
	while (fmt[i] && ft_read_flag (fmt[i], arg))
		i += 1;
	i += ft_read_width (fmt + i, arg);
	if (arg->width == WIDTH_ARG)
		arg->width = va_arg (args, int);
	i += ft_read_precision (fmt + i, arg);
	if (arg->precision == PREC_ARG)
		arg->precision = va_arg (args, int);
	i += ft_read_length (fmt + i, arg);
	i += ft_read_specifier (fmt + i, arg);
	ft_read_value (arg, args);
	return (i);
}

static t_int	ft_sprintf_ubase(char *buff, unsigned long n, int base)
{
	char	n_buff[32];
	t_int	len;
	t_int	i;

	if (n == 0)
	{
		if (buff)
			buff[0] = '0';
		return (1);
	}
	len = 0;
	while (n > 0)
	{
		n_buff[32 - len - 1] = g_digits[n % base];
		n /= base;
		len += 1;
	}
	if (buff)
	{
		i = 0;
		while (i < len)
		{
			buff[i] = n_buff[32 - len + i];
			i += 1;
		}
	}
	return (len);
}

t_int	ft_sprintf_c(char *buff, t_fmt_arg arg)
{
	if (buff)
		*buff = arg.c;
	return (1);
}

t_int	ft_sprintf_s(char *buff, t_fmt_arg arg)
{
	t_int	i;

	i = 0;
	while (arg.s[i])
	{
		if (buff)
			buff[i] = arg.s[i];
		i += 1;
	}
	return (i);
}

t_int	ft_sprintf_p(char *buff, t_fmt_arg arg)
{
	t_int	i;

	if (!arg.p)
	{
		arg.s = "(nil)";
		return (ft_sprintf_s (buff, arg));
	}
	if (buff)
	{
		buff[0] = '0';
		buff[1] = 'x';
	}
	i = 2;
	if (buff)
		i += ft_sprintf_ubase (buff + i, (t_u64)arg.p, 16);
	else
		i += ft_sprintf_ubase (NULL, (t_u64)arg.p, 16);
	return (i);
}

t_int	ft_sprintf_i(char *buff, t_fmt_arg arg)
{
	t_int	i;

	i = 0;
	if (arg.i < 0)
	{
		if (buff)
			buff[0] = '-';
		i += 1;
	}
	arg.u = ABS (arg.i);
	if (buff)
		i += ft_sprintf_u (buff + i, arg);
	else
		i += ft_sprintf_u (NULL, arg);
	return (i);
}

t_int	ft_sprintf_u(char *buff, t_fmt_arg arg)
{
	return (ft_sprintf_ubase (buff, arg.u, 10));
}

t_int	ft_sprintf_x(char *buff, t_fmt_arg arg)
{
	return (ft_sprintf_ubase (buff, arg.i, 16));
}

t_int	ft_vsprintf(char *buff, const char *fmt, va_list va)
{
	t_int		i;
	t_fmt_arg	fmt_arg;
	va_list		args;

	va_copy (args, va);
	i = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt += 1;
			if (*fmt == '%')
			{
				if (buff)
					buff[i] = *fmt;
				fmt += 1;
				i += 1;
			}
			else
			{
				fmt += ft_next_arg (fmt, &fmt_arg, args);
				if (!fmt_func)
					continue ;
				if (buff)
					i += (*fmt_func)(buff + i, fmt_arg);
				else
					i += (*fmt_func)(NULL, fmt_arg);
				continue ;
			}
		}
		if (buff)
			buff[i] = *fmt;
		fmt += 1;
		i += 1;
	}
	if (buff)
		buff[i] = 0;
	va_end (args);
	return (i);
}

t_int	ft_sprintf(char *buff, const char *fmt, ...)
{
	va_list	args;
	int		len;

	va_start (args, fmt);
	len = ft_vsprintf (buff, fmt, args);
	va_end (args);
	return (len);
}

t_int	ft_printf(const char *fmt, ...)
{
	char	*buff;
	va_list	args;
	t_int	len;

	va_start (args, fmt);
	len = ft_vsprintf (NULL, fmt, args);
	buff = (char *)malloc (len + 1);
	ft_vsprintf (buff, fmt, args);
	write (1, buff, len);
	free (buff);
	va_end (args);
	return (len);
}
