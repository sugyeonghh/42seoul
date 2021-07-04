/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 04:37:14 by shong             #+#    #+#             */
/*   Updated: 2021/07/05 05:44:14 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	quick_sort(t_node **a, t_node **b, int size)
{
	int		s_size;
	int		i;

	if (size % 2)
		s_size = (size / 2) + 1;
	else
		s_size = size / 2;
	if (size > 2)
	{
		partition(a, b, find_pivot(*a, size));
		quick_sort(a, b, s_size);
		i = -1;
		while (++i < (size - s_size))
			pa(a, b);
		quick_sort(a, b, size - s_size);
	}
}

void	partition(t_node **a, t_node **b, t_node *pivot)
{
	int		pb_cnt;
	int		ra_cnt;

	pb_cnt = 0;
	ra_cnt = 0;
	while (1)
	{
		if (pb_cnt == pivot->idx)
			break ;
		if ((*a)->value < pivot->value)
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
	while (ra_cnt--)
		rra(a);
}
