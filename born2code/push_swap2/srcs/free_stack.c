/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:51:00 by shong             #+#    #+#             */
/*   Updated: 2021/09/10 22:22:09 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*p;
	t_node	*last;

	if (!*stack)
		return ;
	p = (*stack);
	last = last_node(*stack);
	while (p != last)
	{
		p = p->next;
		free(p->prev);
	}
	free(p);
}
