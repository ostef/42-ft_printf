/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:40:10 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/10 17:45:18 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_int	ft_sprintf_u(t_buff *buff, t_fmt_arg arg)
{
	return (ft_putuint_buff (buff, arg.u, arg.precision, DECIMAL));
}
