/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:09:11 by shong             #+#    #+#             */
/*   Updated: 2021/07/03 05:32:23 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_node *a, t_node *b)
{
	if (stack_size(a) == 2)
		quick_sort1(a);
	else
		quick_sort2(a, b);
}

void	quick_sort1(t_node *a)
{
	if (a->value > a->next->value)
		sa(&a);
	return ;
}

void	quick_sort2(t_node *a, t_node *b)
{
	
}
