#include "libft.h"

const void	*ft_memchr(const void *p, t_u8 c, t_s64 n)
{
	t_s64	i;

	i = 0;
	while (i < n && ((t_u8 *)p)[i] != c)
		i += 1;
	if (i == n)
		return (NULL);
	return (p + i);
}

const void	*ft_memrchr(const void *p, t_u8 c, t_s64 n)
{
	t_s64	i;

	i = n - 1;
	while (i >= 0 && ((t_u8 *)p)[i] != c)
		i -= 1;
	if (i == -1)
		return (NULL);
	return (p + i);
}
