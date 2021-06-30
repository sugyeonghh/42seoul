/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:23:44 by shong             #+#    #+#             */
/*   Updated: 2021/06/30 18:36:37 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_idx(t_node *stack)
{
	t_node	*p;

	if (!stack)
		return ;
	p = stack;
	while (p)
	{
		p->idx = 0;
		if (!(p->next) || p->next == stack)
			break ;
		p = p->next;
	}
}

t_node	*new_node(int value)
{
	t_node	*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		ft_putstr_fd("Fail to create new node \n", 1);
	new->value = value;
	new->idx = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_node	*last_node(t_node *stack)
{
	t_node	*p;

	if (!stack)
		return (0);
	p = stack;
	while (p)
	{
		if (!(p->next) || p->next == stack)
			break ;
		p = p->next;
	}
	return (p);
}

void	add_stack(t_node **stack, t_node *new_node)
{
	t_node	*last;

	if (!stack || !new_node)
		return ;
	last = last_node(*stack);
	if (!last)
		*stack = new_node;
	else
	{
		last->next = new_node;
		new_node->prev = last;
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
}

int		stack_size(t_node *stack)
{
	int		size;
	t_node	*p;

	if (!stack)
		return (0);
	p = stack;
	size = 0;
	while (p)
	{
		size++;
		if (!(p->next) || p->next == stack)
			break ;
		p = p->next;
	}
	return (size);
}
