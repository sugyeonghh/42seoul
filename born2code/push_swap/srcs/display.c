/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:29:35 by shong             #+#    #+#             */
/*   Updated: 2021/08/29 16:11:08 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	display(t_node *stack, t_pivot pivot)
{
	t_node	*p;
	t_node	*last;

	p = stack;
	last = last_node(stack);
	if (p == NULL)
	{
		printf("NULL \n");
		return ;
	}
	while (p)
	{
		printf("%d", p->value);
		if (p == pivot.small)
			printf("(s)");
		else if (p == pivot.big)
			printf("(b)");
		if (p == last)
			break ;
		p = p->next;
		printf(" -> ");
	}
	printf("\n");
}
