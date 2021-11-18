/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:39:50 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/10 17:45:08 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_int	ft_sprintf_p(t_buff *buff, t_fmt_arg arg)
{
	return (ft_putuint_buff (buff, (t_u64)arg.p, arg.precision, HEX));
}
