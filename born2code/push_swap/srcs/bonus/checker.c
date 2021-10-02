/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:59:56 by shong             #+#    #+#             */
/*   Updated: 2021/10/02 20:48:06 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	checker(t_node **a, t_node **b)
{
	char	*line;

	line = 0;
	while (get_next_line(0, &line) > 0)
	{
		run_cmd(line, a, b);
		free(line);
	}
	free(line);
}

void	run_cmd(char *line, t_node **a, t_node **b)
{
	if (!ft_strncmp(line, "sa", ft_strlen(line)))
		sa(a);
	else if (!ft_strncmp(line, "sb", ft_strlen(line)))
		sb(b);
	else if (!ft_strncmp(line, "ss", ft_strlen(line)))
		ss(a, b);
	else if (!ft_strncmp(line, "pa", ft_strlen(line)))
		pa(a, b);
	else if (!ft_strncmp(line, "pb", ft_strlen(line)))
		pb(a, b);
	else if (!ft_strncmp(line, "ra", ft_strlen(line)))
		ra(a);
	else if (!ft_strncmp(line, "rb", ft_strlen(line)))
		rb(b);
	else if (!ft_strncmp(line, "rr", ft_strlen(line)))
		rr(a, b);
	else if (!ft_strncmp(line, "rra", ft_strlen(line)))
		rra(a);
	else if (!ft_strncmp(line, "rrb", ft_strlen(line)))
		rrb(b);
	else if (!ft_strncmp(line, "rrr", ft_strlen(line)))
		rrr(a, b);
}
