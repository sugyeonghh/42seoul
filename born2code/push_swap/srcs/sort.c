/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:09:11 by shong             #+#    #+#             */
/*   Updated: 2021/07/02 19:21:51 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_node *a, t_node *b)
{
	view_stack(a); view_stack(b); printf("\n");
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	view_stack(a); view_stack(b); printf("\n");
	rr(&a, &b);
	view_stack(a); view_stack(b); printf("\n");
	rrr(&a, &b);
	view_stack(a); view_stack(b); printf("\n");
	sa(&a);
	view_stack(a); view_stack(b); printf("\n");
	ss(&a, &b);
	view_stack(a); view_stack(b); printf("\n");



}
