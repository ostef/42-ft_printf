#include "libft.h"
#include <unistd.h>

t_s64	ft_fputstr(t_file f, t_cstr s)
{
	t_s64	i;

	i = 0;
	while (s[i])
		i += ft_fputchar (f, s[i]);
	return (i);
}

t_s64	ft_putstr(t_cstr s)
{
	return (ft_fputstr (STDOUT, s));
}

t_s64	ft_fputstrn(t_file f, t_cstr s, t_s64 n)
{
	t_s64	i;

	i = 0;
	while (i < n && s[i])
		i += ft_fputchar (f, s[i]);
	return (i);
}

t_s64	ft_putstrn(t_cstr s, t_s64 n)
{
	return (ft_fputstrn (STDOUT, s, n));
}
