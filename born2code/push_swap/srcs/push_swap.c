/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:18:46 by shong             #+#    #+#             */
/*   Updated: 2021/07/07 15:02:04 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
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
	pivot = find_pivot(stack, stack_size(stack));
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

	a = argv_to_stack(argc, argv);
	b = NULL;
	view_stack(a); view_stack(b); printf("\n[commands]\n");
	if (!invalid_check(a) && stack_size(a) > 1)
		sort(&a, &b);
	if (is_sorted(a)) printf("\n>> stack a is sorted! <<\n");
	else printf("\n>> stack a is NOT sorted!!!!!!! <<\n");
	view_stack(a); view_stack(b); printf("\n");
	return (0);
}
