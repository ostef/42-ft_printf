/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:50:38 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/18 12:56:48 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_buff
{
	char	*data;
	t_u64	count;
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

typedef t_int	(*t_fmt_func) (t_buff *, struct s_fmt_arg);

typedef struct s_fmt_arg
{
	t_fmt_flags		flags;
	t_fmt_width		width;
	t_fmt_precision	precision;
	char			specifier;
	t_fmt_func		func;
	union
	{
		t_int	i;
		t_uint	u;
		char	*s;
		void	*p;
	};
}				t_fmt_arg;

# define BINARY "01"
# define DECIMAL "0123456789"
# define HEX "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

t_int	ft_putchars_buff(t_buff *buff, char c, t_s64 len, t_bool escaped);
t_int	ft_putchar_buff(t_buff *buff, char c, t_bool escaped);
t_int	ft_putstr_buff(t_buff *buff, char *str, t_bool escaped);
t_int	ft_putstrn_buff(t_buff *buff, char *str, t_s64 len, t_bool escaped);
t_int	ft_putuint_buff(t_buff *buff, t_u64 n, t_int min, const char *base);

t_int	ft_read_arg(const char *fmt, t_fmt_arg *arg, va_list args);
void	ft_read_va(t_fmt_arg *arg, va_list args);
t_int	ft_read_flag(char c, t_fmt_arg *arg);
t_int	ft_read_width(const char *fmt, t_fmt_arg *arg);
t_int	ft_read_precision(const char *fmt, t_fmt_arg *arg);
t_int	ft_read_specifier(char c, t_fmt_arg *arg);
t_int	ft_read_uint(const char *str, t_int *out);

t_int	ft_next_arg(const char *fmt, t_buff *buff, va_list args);
t_int	ft_sprintf_with_flags(t_buff *buff, t_fmt_arg arg);
t_int	ft_sprintf_c(t_buff *buff, t_fmt_arg arg);
t_int	ft_sprintf_s(t_buff *buff, t_fmt_arg arg);
t_int	ft_sprintf_p(t_buff *buff, t_fmt_arg arg);
t_int	ft_sprintf_i(t_buff *buff, t_fmt_arg arg);
t_int	ft_sprintf_u(t_buff *buff, t_fmt_arg arg);
t_int	ft_sprintf_x(t_buff *buff, t_fmt_arg arg);
t_int	ft_sprintf_b(t_buff *buff, t_fmt_arg arg);

t_int	ft_vsprintf(char *buff, const char *fmt, va_list va);
t_int	ft_vprintf(const char *fmt, va_list va);
t_int	ft_sprintf(char *buff, const char *fmt, ...);
t_int	ft_printf(const char *fmt, ...);

#endif
