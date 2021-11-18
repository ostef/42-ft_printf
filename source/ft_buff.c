/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 02:45:26 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/18 12:19:00 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*g_chars_to_escape = "\t\v\n\r\b\0";
static const char	*g_escaped_chars = "tvnrb0";

t_int	ft_putchar_buff(t_buff *buff, char c, t_bool escaped)
{
	t_s64	i;

	if (escaped)
	{
		i = 0;
		while (i < (t_s64)(sizeof (g_chars_to_escape) - 1))
		{
			if (c == g_chars_to_escape[i])
			{
				ft_putchar_buff (buff, '\\', FALSE);
				ft_putchar_buff (buff, g_escaped_chars[i], FALSE);
				return (2);
			}
			i += 1;
		}
	}
	if (buff->data)
		buff->data[buff->count] = c;
	buff->count += 1;
	return (1);
}

t_int	ft_putchars_buff(t_buff *buff, char c, t_s64 len, t_bool escaped)
{
	t_s64	i;

	i = 0;
	while (i < len)
		i += ft_putchar_buff (buff, c, escaped);
	return ((t_int)len);
}

t_int	ft_putstr_buff(t_buff *buff, const char *str, t_bool escaped)
{
	t_int	i;

	i = 0;
	while (*str)
	{
		i += ft_putchar_buff (buff, *str, escaped);
		str += 1;
	}
	return (i);
}

t_int	ft_putstrn_buff(t_buff *buff, const char *str, t_s64 len, t_bool escaped)
{
	t_s64	i;

	i = 0;
	while (i < len && str[i])
		i += ft_putchar_buff (buff, str[i], escaped);
	return ((t_int)i);
}

t_int	ft_putuint_buff(t_buff *buff, t_u64 n, t_int min, const char *base)
{
	t_int	len;
	t_int	base_len;
	t_u64	temp;
	t_int	i;

	base_len = (t_int)ft_strlen (base);
	len = 0;
	temp = n;
	while (temp != 0 || len < min || (min < 0 && len == 0))
	{
		temp /= base_len;
		len += 1;
	}
	buff->count += len;
	i = 0;
	while (i < len)
	{
		if (buff->data)
			buff->data[buff->count - i - 1] = base[n % base_len];
		n /= base_len;
		i += 1;
	}
	return (i);
}
