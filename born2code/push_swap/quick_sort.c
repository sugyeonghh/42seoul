/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:46:51 by shong             #+#    #+#             */
/*   Updated: 2021/06/23 15:12:01 by shong            ###   ########.fr       */
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

void	partition(t_stack *a, t_stack *b)
{
	t_node	*pivot;
	t_node	*p;

	pivot = find_pivot(a);
	p = a->first;
	while (p)
	{
		if (p->value < pivot->value)
			pb(a, b);
		else
			ra(a);
	}

}

void	quick_sort(t_stack *stack)
{

}
