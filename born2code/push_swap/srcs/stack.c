/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:23:44 by shong             #+#    #+#             */
/*   Updated: 2021/07/14 23:02:11 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_stack(t_node **stack, int value)
{
	t_node	*new;
	t_node	*last;

	if (!stack)
		return ;
	if (!(new = (t_node *)malloc(sizeof(t_node))))
		ft_putstr_fd("Error\n", 1);
	new->value = value;
	new->idx = 0;
	new->prev = NULL;
	new->next = NULL;
	if (!(last = last_node(*stack)))
		*stack = new;
	else
	{
		last->next = new;
		new->prev = last;
		new->next = *stack;
		(*stack)->prev = new;
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

int		find_mid_pos(t_node *stack, int size)
{
	t_node	*p;
	int		pos;

	p = stack;
	pos = 0;
	set_idx(stack, size);
	while (1)
	{
		if (p->idx == 1)
			break ;
		pos++;
		p = p->next;
	}
	return (pos);
}

int		find_min_pos(t_node *stack, int size)
{
	t_node	*p;
	int		pos;

	p = stack;
	pos = 0;
	set_idx(stack, size);
	while (1)
	{
		if (p->idx == 0)
			break ;
		pos++;
		p = p->next;
	}
	return (pos);
}
