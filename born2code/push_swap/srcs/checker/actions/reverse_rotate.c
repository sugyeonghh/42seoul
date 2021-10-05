/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:56:08 by shong             #+#    #+#             */
/*   Updated: 2021/10/05 23:21:10 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	reverse_rotate(t_node **stack)
{
	if (!*stack || stack_size(*stack) == 1)
		return ;
	else
		*stack = (*stack)->prev;
}

void	rra(t_node **stack)
{
	reverse_rotate(stack);
}

void	rrb(t_node **stack)
{
	reverse_rotate(stack);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
