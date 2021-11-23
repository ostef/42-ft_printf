/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprint_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 01:49:06 by aviscogl          #+#    #+#             */
/*   Updated: 2021/11/23 01:49:06 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

t_s64	ft_sprint_n(t_buff *buff, t_fmt_arg arg, va_list va)
{
	t_int	*n;

	(void)buff;
	(void)arg;
	n = va_arg (va, t_int *);
	*n = (t_int)buff->count;
	return (0);
}
