/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:51:24 by shong             #+#    #+#             */
/*   Updated: 2021/07/02 19:21:32 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_node_idx(t_node *stack)
{
	t_node	*p;

	if (!stack)
		return ;
	p = stack;
	while (p)
	{
		p->idx = 0;
		if (!(p->next) || p->next == stack)
			break ;
		p = p->next;
	}
}

t_node	*new_node(int value)
{
	t_node	*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		ft_putstr_fd("Fail to create new node \n", 1);
	new->value = value;
	new->idx = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_node	*last_node(t_node *stack)
{
	t_node	*p;

	if (!stack)
		return (0);
	p = stack;
	while (p)
	{
		if (!(p->next) || p->next == stack)
			break ;
		p = p->next;
	}
	return (p);
}
