/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:18:46 by shong             #+#    #+#             */
/*   Updated: 2021/08/29 16:19:29 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
