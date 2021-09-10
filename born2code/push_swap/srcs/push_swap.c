/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:18:46 by shong             #+#    #+#             */
/*   Updated: 2021/09/10 22:22:17 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;

	if (argc < 2)
		exit(1);
	a = pre(argc, argv);
	b = NULL;
	if (stack_size(a) > 1)
		sort(&a, &b, stack_size(a));
	free_stack(&a);
	free_stack(&b);
	system("leaks push_swap > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
