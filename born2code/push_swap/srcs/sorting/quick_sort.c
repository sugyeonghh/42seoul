/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 04:37:14 by shong             #+#    #+#             */
/*   Updated: 2021/07/04 06:12:35 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	partition(t_node **a, t_node **b, t_node *pivot)
{
	int		num;
	int		i;

	num = stack_size(*a) / 2;
	i = 0;
	while (i < num)
	{
		if ((*a)->value < pivot->value)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	while ((*a) != pivot)
		ra(a);
}

void	quick_sort(t_node **a, t_node **b)
{
	t_node	*pivot;

	pivot = find_pivot(*a);
	partition(a, b, pivot);
	if (!is_sorted(*a))
		pb(a, b);
	sort(a, b);
	while (*b != pivot)
		pa(a, b);
	pa(a, b);
}
