/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:00:57 by shong             #+#    #+#             */
/*   Updated: 2021/07/05 04:22:10 by shong            ###   ########.fr       */
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

t_node	*find_pivot(t_node *stack, int size)
{
	t_node	*pivot;
	t_node	*p1;
	t_node	*p2;
	int		i;
	int		j;

	init_idx(stack);
	pivot = NULL;
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
		if (p1->idx == (size / 2))
			pivot = p1;
		p1 = p1->next;
	}
	return (pivot);
}
