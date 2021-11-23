/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprint_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:37:34 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/18 12:15:43 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

t_s64	ft_sprint_c(t_buff *buff, t_fmt_arg arg, va_list va)
{
	char	c;
	
	c = (char)va_arg (va, t_int);
	return (ft_putchar_buff (buff, c, arg.flags & FLAG_ESCAPED));
}
