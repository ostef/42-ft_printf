#include "libft.h"

t_s64	ft_fputchar(t_file f, t_u8 c)
{
	write (f, &c, 1);
	return (1);
}

t_s64	ft_putchar(t_u8 c)
{
	return (ft_fputchar (STDOUT, c));
}
