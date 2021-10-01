/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 03:15:28 by shong             #+#    #+#             */
/*   Updated: 2021/07/14 23:17:57 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_case_3(t_node **a)
{
	int		mid_pos;

	mid_pos = find_mid_pos(*a, 3);
	if (mid_pos == 0)
	{
		if ((*a)->next->value < (*a)->next->next->value)
			sa(a);
		else
			rra(a);
	}
	else if (mid_pos == 1)
	{
		sa(a);
		rra(a);
	}
	else
	{
		if ((*a)->value < (*a)->next->value)
		{
			rra(a);
			sa(a);
		}
		else
			ra(a);
	}
}

void	sort_case_4(t_node **a, t_node **b)
{
	int		min_pos;

	min_pos = find_min_pos(*a, 4);
	if (min_pos == 1)
		sa(a);
	else if (min_pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_pos == 3)
		rra(a);
	if (is_sorted(*a))
		return ;
	pb(a, b);
	sort_case_3(a);
	pa(a, b);
}
