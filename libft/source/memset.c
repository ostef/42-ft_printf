#include "libft.h"

void	*ft_memset(void *dst, t_u8 c, t_s64 n)
{
	t_s64	i;

	i = 0;
	while (i < n)
	{
		((t_u8 *)dst)[i] = c;
		i += 1;
	}
	return (dst);
}
