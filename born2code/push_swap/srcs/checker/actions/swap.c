/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:03:57 by shong             #+#    #+#             */
/*   Updated: 2021/10/05 23:21:25 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	swap(t_node **stack)
{
	t_node	*p1;
	t_node	*p2;
	t_node	*last;

	if (!*stack || stack_size(*stack) == 1)
		return ;
	else if (stack_size(*stack) == 2)
		*stack = (*stack)->next;
	else
	{
		last = last_node(*stack);
		p1 = *stack;
		p2 = (*stack)->next;
		p2->prev = last;
		p1->prev = p2;
		p1->next = p2->next;
		p2->next->prev = p1;
		p2->next = p1;
		last->next = p2;
		*stack = p2;
	}
}

void	sa(t_node **stack)
{
	swap(stack);
}

void	sb(t_node **stack)
{
	swap(stack);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
}
