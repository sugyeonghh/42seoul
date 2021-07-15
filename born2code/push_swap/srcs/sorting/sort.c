/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:09:11 by shong             #+#    #+#             */
/*   Updated: 2021/07/14 22:42:06 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		is_sorted(t_node *a)
{
	t_node	*p1;
	t_node	*p2;

	p1 = a;
	p2 = a->next;
	while (p1 != last_node(a))
	{
		if (p1->value > p2->value)
			return (0);
		p1 = p1->next;
		p2 = p2->next;
	}
	return (1);
}

void	sort(t_node **a, t_node **b, int size)
{
	if (is_sorted(*a))
		return ;
	else if (size == 2)
		sa(a);
	else if (size == 3)
		sort_case_3(a);
	else if (size == 4)
		sort_case_4(a, b);
	else
		quick_sort(a, b, stack_size(*a));
	return ;
}
