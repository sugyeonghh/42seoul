/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:23:44 by shong             #+#    #+#             */
/*   Updated: 2021/07/02 19:21:57 by shong            ###   ########.fr       */
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
		add_stack(&a, new_node(ft_atoi(argv[i++])));
	return (a);
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

void	view_stack(t_node *stack)
{
	t_node	*p;
	t_node	*pivot;

	printf("[stack] ");
	if (!stack)
	{
		printf("NULL \n");
		return ;
	}
	pivot = find_pivot(stack);
	p = stack;
	while (p)
	{
		printf("%d", p->value);
		if (p == pivot)
			printf("(p)");
		p = p->next;
		if (p == stack)
			break ;
		printf(" -> ");
	}
	printf("\n");
}
