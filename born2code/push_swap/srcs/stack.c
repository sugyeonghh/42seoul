/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:23:44 by shong             #+#    #+#             */
/*   Updated: 2021/07/03 04:56:27 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*argv_to_stack(int argc, char *argv[])
{
	t_node	*a;
	int		i;

	if (argc < 2)
	{
		ft_putstr_fd("No arguments!\n", 1);
		exit(-1);
	}
	a = NULL;
	i = 1;
	while (i < argc)
		add_stack(&a, ft_atoi(argv[i++]));
	return (a);
}

void	add_stack(t_node **stack, int value)
{
	t_node	*new;
	t_node	*last;

	if (!stack)
		return ;
	if (!(new = (t_node *)malloc(sizeof(t_node))))
		ft_putstr_fd("Fail to create new node \n", 1);
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
