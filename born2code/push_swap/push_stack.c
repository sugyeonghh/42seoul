/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:54:40 by shong             #+#    #+#             */
/*   Updated: 2021/06/20 18:30:17 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *stack1, t_stack *stack2)
{
	t_node	*node;

	node = stack2->first;
	stack2->first = node->next;
	node->next = stack1->first;
	node->prev = stack1->last;
	stack1->first->prev = node;
	stack1->last->next = node;
	stack1->first = node;
	stack2->first->prev = stack2->last;
	stack2->last->next = stack2->first;
}

void	pa(t_stack *a, t_stack *b)
{
	push_stack(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	push_stack(b, a);
	ft_putstr_fd("pb\n", 1);
}
