/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 05:23:14 by shong             #+#    #+#             */
/*   Updated: 2021/07/07 15:03:16 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		invalid_check(t_node *stack)
{
	if (is_duplicate(stack))
	{
		ft_putstr_fd("duplicate error! \n", 1);
		exit(1);
	}
	return (0);
}

int		is_duplicate(t_node *stack)
{
	t_node	*p;
	int		*check;
	int		i;
	int		size;

	size = stack_size(stack);
	find_pivot(stack, size);
	check = (int *)malloc(sizeof(int) * size);
	p = stack;
	while (p)
	{
		check[p->idx] += 1; 
		if (!(p->next) || p->next == stack)
			break ;
		p = p->next;
	}
	i = -1;
	while (++i < size)
		if (check[i] == 2)
			return (1);
	return (0);
}
