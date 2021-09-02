/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:00:57 by shong             #+#    #+#             */
/*   Updated: 2021/08/29 16:35:06 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_idx(t_node *stack)
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

void	set_idx(t_node *stack, int size)
{
	t_node	*p1;
	t_node	*p2;
	int		i;
	int		j;

	init_idx(stack);
	p1 = stack;
	i = -1;
	while (++i < size)
	{
		p2 = stack;
		j = -1;
		while (++j < size)
		{
			if (p2->value < p1->value)
				p1->idx += 1;
			p2 = p2->next;
		}
		p1 = p1->next;
	}
}

void	init_pivot(t_pivot *pivot)
{
	pivot->small = NULL;
	pivot->big = NULL;
}

t_pivot	find_pivot(t_node *stack, int size)
{
	t_pivot	pivot;
	t_node	*p;
	int		small;
	int		big;
	int		i;

	small = size / 3 * 1;
	big = size / 3 * 2;
	init_pivot(&pivot);
	set_idx(stack, size);
	p = stack;
	i = -1;
	while (++i < size)
	{
		if (p->idx == small)
			pivot.small = p;
		else if (p->idx == big)
			pivot.big = p;
		p = p->next;
	}
	return (pivot);
}
