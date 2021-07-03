/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:09:11 by shong             #+#    #+#             */
/*   Updated: 2021/07/04 04:02:58 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	sort(t_node **a, t_node **b)
{
	if (is_sorted(*a))
		return ;
	else if (stack_size(*a) == 2)
		sa(a);
	else if (stack_size(*a) == 3)
		sort_case_3(a);
	else if (stack_size(*a) == 4)
		sort_case_4(a, b);
	else if (stack_size(*a) == 5)
		sort_case_5(a, b);
	return ;
}
