#include "libft.h"

t_s64	ft_strlen(t_cstr s)
{
	t_s64	len;

	len = 0;
	while (s[len])
		len += 1;
	return (len);
}

t_cstr	ft_strchr(t_cstr s, t_u8 c)
{
	t_s64	i;

	i = 0;
	while (s[i] && s[i] != c)
		i += 1;
	if (s[i] == c)
		return (s + i);
	return (NULL);
}

t_cstr	ft_strnchr(t_cstr s, t_u8 c, t_s64 n)
{
	t_s64	i;

	i = 0;
	while (i < n && s[i] && s[i] != c)
		i += 1;
	if (i != n && s[i] == c)
		return (s + i);
	return (NULL);
}

t_cstr	ft_strrchr(t_cstr s, t_u8 c)
{
	return (ft_strnrchr (s, c, ft_strlen (s)));
}

t_cstr	ft_strnrchr(t_cstr s, t_u8 c, t_s64 n)
{
	t_s64	i;

	i = n;
	while (i >= 0 && s[i] != c)
		i -= 1;
	if (i == -1)
		return (NULL);
	return (s + i);
}
