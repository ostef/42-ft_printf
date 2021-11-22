#include "libft.h"

t_str	ft_strcpy(t_str dst, t_cstr src)
{
	t_s64	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = 0;
	return (dst);
}

t_str	ft_strncpy(t_str dst, t_cstr src, t_s64 n)
{
	t_s64	i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = 0;
	return (dst);
}
