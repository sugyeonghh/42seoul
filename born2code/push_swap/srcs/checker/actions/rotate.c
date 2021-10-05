/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:41:32 by shong             #+#    #+#             */
/*   Updated: 2021/10/05 23:21:17 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	rotate(t_node **stack)
{
	if (!*stack || stack_size(*stack) == 1)
		return ;
	else
		*stack = (*stack)->next;
}

void	ra(t_node **stack)
{
	rotate(stack);
}

void	rb(t_node **stack)
{
	rotate(stack);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}
