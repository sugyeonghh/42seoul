/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 05:23:14 by shong             #+#    #+#             */
/*   Updated: 2021/07/10 03:10:50 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*pre(int argc, char **argv)
{
	t_node	*res;
	char	**tmp;
	int		i;
	int		j;

	if (argc < 2)
	{
		ft_putstr_fd("input error: need two or more\n", 1);
		exit(1);
	}
	res = NULL;
	i = 1;
	while (i < argc)
	{
		tmp = ft_split(argv[i++], ' ');
		j = -1;
		while (tmp[++j])
		{
			allnum_check(tmp[j]);
			add_stack(&res, ascii_to_integer(tmp[j]));
		}
		free(tmp);
	}
	duplicate_check(res);
	return (res);
}

void	allnum_check(char *s)
{
	int		i;

	i = -1;
	while (++i < (int)ft_strlen(s))
		if (!ft_isdigit(s[i]))
		{
			ft_putstr_fd("input error: including character\n", 1);
			exit(1);
		}
}

void	ascii_to_integer(char *s)
{
	return ;
}

void	duplicate_check(t_node *stack)
{
	t_node	*p;
	int		*check;
	int		i;
	int		size;

	size = stack_size(stack);
	find_pivot(stack, size);
	check = ft_calloc(size, sizeof(int));
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
		if (check[i] >= 2)
		{
			ft_putstr_fd("duplicate error! \n", 1);
			exit(1);
		}
	free(check);
}
