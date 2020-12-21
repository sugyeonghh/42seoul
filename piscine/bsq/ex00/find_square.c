/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sook-yeon <sook-yeon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:50:48 by sook-yeon         #+#    #+#             */
/*   Updated: 2020/12/20 03:06:06 by sook-yeon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_map.h"
#include "pre_processing.h"
#include <stdio.h>

int		ft_sqrt(int nb)
{
	int a;

	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	a = 2;
	while (a <= nb / a)
	{
		if (a == nb / a)
			return (a);
		a++;
	}
	return (0);
}

void	ft_fill_x(s_map *map, int x, int y, int size)
{
	int i;
	int j;

	i = x;
	while (i < size)
	{
		j = y;
		while (j < size)
		{
			map -> map[i][j] = 'x';
			j++;
		}
		i++;
	}
	map -> square_size = size;
}

s_map	*ft_find_ox(s_map *map, int x, int y)
{
	int		size;
	int		i;
	int		j;
	s_map	*tmp;
	
	size = 0;
	tmp = map;
	i = y;
	while (i)
	{
		j = x;
		while (j <= i)
		{
			if (tmp -> map[i][j] == 'o')
				return (0);
			else if (tmp -> map[i][j] == '.')
				size++;
			j++;
		}
		i++;
	}
	if (ft_sqrt(size) != 0)
		ft_fill_x(tmp, x, y, size);
	return (tmp);
}

s_map	*ft_find_sqaure(char *map)
{
	// int 	size;
	int 	i;
	int 	j;
	s_map	*matrix_map;
	s_map	*result_map;

	matrix_map = ft_pre_process(map);
	result_map = 0;
	i = 0;
	j = 0;
	// 아래 while문 수정해야됨 
	// while 조건식 수정 필요 
	while (i < matrix_map -> map[i][j])
	{
		j = 0;
		while (j < matrix_map -> map[i][j])
		{
			if (ft_find_ox(matrix_map, i, j) -> square_size > result_map -> square_size)
				result_map = ft_find_ox(matrix_map, i, j);
			j++;
		}
		i++;
	}
	return (result_map);
}