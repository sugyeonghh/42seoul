/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 02:05:59 by shong             #+#    #+#             */
/*   Updated: 2020/12/30 00:21:19 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new;
	t_list	*p;

	res = NULL;
	p = lst;
	while (p)
	{
		if (!(new = ft_lstnew(f(p->content))))
		{
			ft_lstclear(&res, del);
			return (0);
		}
		ft_lstadd_back(&res, new);
		p = p->next;
	}
	return (res);
}
