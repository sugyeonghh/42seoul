/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:49:28 by shong             #+#    #+#             */
/*   Updated: 2021/09/02 18:42:30 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_over_4(t_node **a, t_node **b)
{
	int		size;
	t_pivot	pivot;

	size = stack_size(*a);
	pivot = find_pivot(*a, size);
	if (is_sorted(*a))
		return ;
	if (size <= 4)
		sort(a, b, size);
	else
		a_to_b(a, b, pivot);
}

void	a_to_b(t_node **a, t_node **b, t_pivot pivot)
{
	int		pb_cnt;
	int		ra_cnt;

	pb_cnt = 0;
	ra_cnt = 0;
	while ((*a) && pb_cnt != pivot.small->idx + 1)
	{
		if ((*a)->value <= pivot.small->value)
		{
			pb(a, b);
			pb_cnt++;
		}
		else
		{
			ra(a);
			ra_cnt++;
		}
	}
	sort_over_4(a, b);
	b_to_a(a, b, pivot);
}

void	b_to_a(t_node **a, t_node **b, t_pivot pivot)
{
	int		pa_cnt;
	int		ra_cnt;

	pa_cnt = 0;
	ra_cnt = 0;
	while ((*b) && pa_cnt != pivot.small->idx + 1)
	{
		if ((*a)->value > (*b)->value)
			b_to_a_pa(a, b, &ra_cnt, &pa_cnt);
		else
		{
			ra(a);
			ra_cnt++;
		}
	}
	while (ra_cnt--)
		rra(a);
}

void	b_to_a_pa(t_node **a, t_node **b, int *ra_cnt, int *pa_cnt)
{
	if ((*ra_cnt) && last_node(*a)->value > (*b)->value)
	{
		rra(a);
		(*ra_cnt)--;
	}
	else
	{
		pa(a, b);
		(*pa_cnt)++;
	}
}
