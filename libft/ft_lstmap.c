/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:47:17 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/06 16:31:27 by soumanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*curr;
	void	*content;

	res = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		curr = ft_lstnew (content);
		if (!curr)
		{
			if (del)
				(*del)(content);
			ft_lstclear (&res, del);
			return (NULL);
		}
		ft_lstadd_back (&res, curr);
		lst = lst->next;
	}
	return (res);
}
