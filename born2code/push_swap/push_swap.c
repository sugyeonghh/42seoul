/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:18:46 by shong             #+#    #+#             */
/*   Updated: 2021/07/02 19:23:55 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;

	a = argv_to_stack(argc, argv);
	b = NULL;
	if (stack_size(a) == 1)
		return (0);

	sort(a, b);

	return (0);
}
