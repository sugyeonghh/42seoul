/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:18:46 by shong             #+#    #+#             */
/*   Updated: 2021/09/04 03:41:42 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap/includes/push_swap.h"
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

int		main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	t_pivot	pivot;

	if (argc < 2)
		exit(1);
	a = pre(argc, argv);
	b = NULL;
	pivot = find_pivot(a, stack_size(a));
	printf("================ before ================\n");
	printf("A: "); display(a, pivot); printf("B: "); display(b, pivot); printf("\n");
	printf("================ sorting ================\n");
	if (stack_size(a) > 1)
		sort(&a, &b, stack_size(a));
	printf("================ after =================\n");
	printf("A: "); display(a, pivot); printf("B: "); display(b, pivot); printf("\n");
	if (is_sorted(a))
		printf(">> SUCCESS! \n");
	else
		printf(">> FAIL! \n");
	return (0);
}
