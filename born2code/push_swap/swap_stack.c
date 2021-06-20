/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:51:20 by shong             #+#    #+#             */
/*   Updated: 2021/06/20 18:30:53 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	node1 = stack->first;
	node2 = stack->first->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node1->next = node2->next;
	node2->next = node1;
	stack->first = node2;
	stack->last->next = node2;
}

void	sa(t_stack *a)
{
	swap_stack(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	swap_stack(b);
	ft_putstr_fd("sb\n", 1);
}
