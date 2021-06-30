/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:00:57 by shong             #+#    #+#             */
/*   Updated: 2021/06/30 17:23:16 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_pivot(t_node *stack)
{
	t_node	*pivot;
	t_node	*p1;
	t_node	*p2;

	init_idx(stack);
	pivot = NULL;
	p1 = stack;
	while (p1)
	{
		p2 = stack;
		while (p2)
		{
			if (p1->value > p2->value)
				p1->idx += 1;
			if (!(p2->next) || p2->next == stack)
				break ;
			p2 = p2->next;
		}
		if (p1->idx == (stack_size(stack) / 2))
			pivot = p1;
		if (!(p1->next) || p1->next == stack)
			break ;
		p1 = p1->next;
	}
	return (pivot);
}
