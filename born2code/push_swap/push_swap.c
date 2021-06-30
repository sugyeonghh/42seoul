/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:18:46 by shong             #+#    #+#             */
/*   Updated: 2021/06/30 18:55:01 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

int		main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	int		i;

	if (argc < 2)
	{
		ft_putstr_fd("No arguments!\n", 1);
		exit(1);
	}
	a = NULL;
	b = NULL;
	i = 1;
	while (i < argc)
		add_stack(&a, new_node(ft_atoi(argv[i++])));

	// swap
/*	view_stack(a); view_stack(b); printf("\n");
	sa(&a);
	view_stack(a); view_stack(b); printf("\n");
	sb(&a);
	view_stack(a); view_stack(b); printf("\n");
	ss(&a, &a);
	view_stack(a); view_stack(b); printf("\n"); */


	// push
	view_stack(a); view_stack(b); printf("\n");
	pa(&a, &b);
	view_stack(a); view_stack(b); printf("\n");
	pb(&a, &b);
	view_stack(a); view_stack(b); printf("\n");
	pb(&a, &b);
	view_stack(a); view_stack(b); printf("\n");
	pa(&a, &b);
	view_stack(a); view_stack(b); printf("\n");
	pb(&a, &b);
	view_stack(a); view_stack(b); printf("\n");
	pb(&a, &b);
	view_stack(a); view_stack(b); printf("\n");
	pb(&a, &b);
	view_stack(a); view_stack(b); printf("\n");
	pb(&a, &b);
	view_stack(a); view_stack(b); printf("\n");




	return (0);
}
