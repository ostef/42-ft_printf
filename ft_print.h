/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:50:38 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/23 13:47:53 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_buff
{
	char	*data;
	t_s64	count;
}				t_buff;

typedef enum e_fmt_flags
{
	FLAG_NONE = 0x00,
	FLAG_LJUSTIFY = 0x01,
	FLAG_SIGN = 0x02,
	FLAG_SPACE = 0x04,
	FLAG_HASH = 0x08,
	FLAG_ZPAD = 0x10,
	FLAG_ESCAPED = 0x20
}				t_fmt_flags;

typedef enum e_fmt_width
{
	WIDTH_ARG = -2,
	WIDTH_DEFAULT = -1
}				t_fmt_width;

typedef enum e_fmt_precision
{
	PREC_ARG = -2,
	PREC_DEFAULT = -1
}				t_fmt_precision;

struct			s_fmt_arg;

typedef t_s64	(*t_fmt_func) (t_buff *, struct s_fmt_arg, va_list va);

typedef struct s_fmt_arg
{
	t_fmt_flags		flags;
	t_fmt_width		width;
	t_fmt_precision	precision;
	char			specifier;
	t_fmt_func		func;
}				t_fmt_arg;

t_s64	ft_putchars_buff(t_buff *buff, char c, t_s64 len, t_bool escaped);
t_s64	ft_putchar_buff(t_buff *buff, char c, t_bool escaped);
t_s64	ft_putstr_buff(t_buff *buff, t_cstr str, t_bool escaped);
t_s64	ft_putstrn_buff(t_buff *buff, t_cstr str, t_s64 len, t_bool escaped);
t_s64	ft_putuint_buff(t_buff *buff, t_u64 n, t_int min, const char *base);

t_s64	ft_next_arg(t_cstr fmt, t_buff *buff, va_list va);
t_s64	ft_read_arg(t_cstr fmt, t_fmt_arg *arg, va_list va);

t_s64	ft_sprint_c(t_buff *buff, t_fmt_arg arg, va_list va);
t_s64	ft_sprint_s(t_buff *buff, t_fmt_arg arg, va_list va);
t_s64	ft_sprint_p(t_buff *buff, t_fmt_arg arg, va_list va);
t_s64	ft_sprint_i(t_buff *buff, t_fmt_arg arg, va_list va);
t_s64	ft_sprint_u(t_buff *buff, t_fmt_arg arg, va_list va);
t_s64	ft_sprint_x(t_buff *buff, t_fmt_arg arg, va_list va);
t_s64	ft_sprint_b(t_buff *buff, t_fmt_arg arg, va_list va);
t_s64	ft_sprint_n(t_buff *buff, t_fmt_arg arg, va_list va);

t_s64	ft_vsprint(t_str buff, t_cstr fmt, va_list va);
t_s64	ft_sprint(t_str buff, t_cstr fmt, ...);
t_s64	ft_vsprintln(t_str buff, t_cstr fmt, va_list va);
t_s64	ft_sprintln(t_str buff, t_cstr fmt, ...);
t_s64	ft_vfprint(t_file f, t_cstr fmt, va_list va);
t_s64	ft_fprint(t_file f, t_cstr fmt, ...);
t_s64	ft_vfprintln(t_file f, t_cstr fmt, va_list va);
t_s64	ft_fprintln(t_file f, t_cstr fmt, ...);
t_s64	ft_vprint(t_cstr fmt, va_list va);
t_s64	ft_print(t_cstr fmt, ...);
t_s64	ft_vprintln(t_cstr fmt, va_list va);
t_s64	ft_println(t_cstr fmt, ...);

#endif
