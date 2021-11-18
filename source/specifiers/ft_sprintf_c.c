/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:37:34 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/18 12:15:43 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_int	ft_sprintf_c(t_buff *buff, t_fmt_arg arg)
{
	return (ft_putchar_buff (buff, (char)arg.i, arg.flags & FLAG_ESCAPED));
}
