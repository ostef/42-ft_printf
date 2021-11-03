#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

typedef enum e_fmt_flags
{
	FLAG_NONE = 0x00,
	FLAG_LJUSTIFY = 0x01,
	FLAG_SIGN = 0x02,
	FLAG_HASH = 0x04,
	FLAG_ZPAD = 0x08
}	t_fmt_flags;

typedef enum e_fmt_width
{
	WIDTH_ARG = -2,
	WIDTH_DEFAULT = -1
}	t_fmt_width;

typedef enum e_fmt_precision
{
	PREC_ARG = -2,
	PREC_DEFAULT = -1
}	t_fmt_precision;

typedef enum e_fmt_length
{
	LENGTH_NONE = 0,
	LENGTH_H = 1,
	LENGTH_HH = 2,
	LENGTH_L = 3,
	LENGTH_LL = 4,
	LENGTH_J = 5,
	LENGTH_Z = 6,
	LENGTH_COUNT = 7
}	t_fmt_length;

typedef t_int (*t_fmt_func) (char *, t_fmt_arg);

typedef struct s_fmt_arg
{
	t_fmt_flags		flags;
	t_fmt_width		width;
	t_fmt_precision	precision;
	t_fmt_length	length;
	char			specifier;
	t_fmt_func		func;
	union
	{
		long			as_long;
		unsigned long	as_ulong;
		char			*as_str;
		void			*as_ptr;
	};
}	t_fmt_arg;

t_int	ft_sprintf(char *buff, const char *fmt, ...);
t_int	ft_printf(const char *fmt, ...);

t_int	ft_sprintf_c(char *buff, t_fmt_arg arg);
t_int	ft_sprintf_s(char *buff, t_fmt_arg arg);
t_int	ft_sprintf_p(char *buff, t_fmt_arg arg);
t_int	ft_sprintf_i(char *buff, t_fmt_arg arg);
t_int	ft_sprintf_u(char *buff, t_fmt_arg arg);
t_int	ft_sprintf_x(char *buff, t_fmt_arg arg);


#endif
