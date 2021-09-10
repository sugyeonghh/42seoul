/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 05:23:14 by shong             #+#    #+#             */
/*   Updated: 2021/09/10 22:02:54 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*pre(int argc, char **argv)
{
	t_node	*res;
	char	**tmp;
	int		i;
	int		j;

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
		j = 0;
		while (tmp[j])
			free(tmp[j++]);
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
	{
		if (s[i] != '-' && !ft_isdigit(s[i]))
		{
			ft_putstr_fd("Error\n", 1);
			exit(1);
		}
	}
}

int	ascii_to_integer(char *s)
{
	int			sign;
	int			cnt;
	long long	num;

	sign = 1;
	while (*s == '\t' || *s == '\n' || *s == '\v'
		|| *s == '\f' || *s == '\r' || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign *= -1;
	num = 0;
	cnt = 0;
	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + (*s++ - 48);
		cnt++;
	}
	if ((num * sign) < INT_MIN || (num * sign) > INT_MAX)
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	return ((int)num * sign);
}

void	duplicate_check(t_node *stack)
{
	int		*check;
	int		i;
	int		size;

	size = stack_size(stack);
	set_idx(stack, size);
	check = ft_calloc(size, sizeof(int));
	i = -1;
	while (++i < size)
	{
		check[stack->idx] += 1;
		if (!(stack->next))
			break ;
		stack = stack->next;
	}
	i = -1;
	while (++i < size)
	{
		if (check[i] >= 2)
		{
			ft_putstr_fd("Error\n", 1);
			exit(1);
		}
	}
	free(check);
}
