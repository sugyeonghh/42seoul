/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:18:46 by shong             #+#    #+#             */
/*   Updated: 2021/06/24 19:42:07 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	t_node	*a;
	int		i;
	t_node	*p;

	if (argc < 2)
		ft_putstr_fd("No arguments!\n", 1);
	i = 1;
	while (i < argc)
		add_stack(&a, new_node(ft_atoi(argv[i++])));
	p = a;
	while (p)
	{
		printf("%d -> ", p->value);
		p = p->next;
		if (p == a)
			break;
	}
	printf("\n");
	return (0);
}
