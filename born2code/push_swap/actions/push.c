/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:49:51 by shong             #+#    #+#             */
/*   Updated: 2021/06/30 18:48:34 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_node **a, t_node **b)
{
	t_node	*p1;
	t_node	*p2;

	if (!(*b))
		return ;
	p1 = *a;
	p2 = (*b)->next;
	p2->prev = last_node(*b);
	(last_node(*b))->next = p2;
	(*b)->prev = last_node(*a);
	(*b)->next = p1;
	if (!p1)
		*a = *b;
	else
		p1->prev = *b;
	(last_node(*a))->next = *b;
	*a = *b;
	*b = p2;
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_putstr_fd("pa \n", 1);
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
	ft_putstr_fd("pb \n", 1);
}
