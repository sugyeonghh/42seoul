/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:13:20 by shong             #+#    #+#             */
/*   Updated: 2021/06/22 17:43:30 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_pivot(t_stack *stack)
{
	t_node	*pivot;
	t_node	*p1;
	t_node	*p2;

	p1 = stack->first;
	while (p1)
	{
		p2 = stack->first;
		while (p2)
		{
			if (p2->value < p1->value)
				p1->idx++;
			p2 = p2->next;
			if (p2 == stack->first)
				break;
		}
		if (p1->idx == (stack->size / 2))
			pivot = p1;
		p1 = p1->next;
		if (p1 == stack->first)
			break;
	}
	return (pivot);
}
