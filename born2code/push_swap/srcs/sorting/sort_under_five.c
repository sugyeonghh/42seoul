/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 03:15:28 by shong             #+#    #+#             */
/*   Updated: 2021/07/04 04:17:35 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_case_3(t_node **a)
{
	t_node	*pivot;

	pivot = find_pivot(*a);
	if ((*a)->value < pivot->value)
	{
		rra(a);
		sa(a);
	}
	else if ((*a) == pivot)
	{
		if ((*a)->next->value < pivot->value)
			sa(a);
		else
			rra(a);
	}
	else
	{
		if ((*a)->next->value < pivot->value)
			ra(a);
		else
		{
			sa(a);
			rra(a);
		}
	}
}

void	sort_case_4(t_node **a, t_node **b)
{
	int		min_pos;

	min_pos = min_node_pos(*a);
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

void	sort_case_5(t_node **a, t_node **b)
{
	t_node	*pivot;
	int		i;

	pivot = find_pivot(*a);
	i = 0;
	while (i < 2)
	{
		if ((*a)->value < pivot->value)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	if (!is_sorted(*a))
		sort_case_3(a);
	if (is_sorted(*b))
		sb(b);
	pa(a, b);
	pa(a, b);
}
