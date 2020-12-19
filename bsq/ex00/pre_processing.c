/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sook-yeon <sook-yeon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:51:02 by sook-yeon         #+#    #+#             */
/*   Updated: 2020/12/20 02:27:28 by sook-yeon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_map.h"

char	**ft_into_matrix(char *map, int x, int y)
{
	char 	**tmp;
	int		i;
	int		j;
	int		m_idx;

	tmp = (char**)malloc(sizeof(char*) * y);
	i = 0;
	while (i < y)
		tmp[i++] = (char*)malloc(sizeof(char) * x);
	i = 0;
	m_idx = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			tmp[i][j] = 0;
			tmp[i][j++] = map[m_idx++];
		}
		i++;
	}
	return (tmp);
}

s_map	*ft_pre_process(char *map)
{
	int		x;
	int 	y;
	s_map 	*matrix_map;

	matrix_map = (s_map*)malloc(sizeof(s_map));
	x = 0;
	y = 0;
	while (map[x] != '\n')
		x++;
	while (map[y] != 0)
		y++;
	y = y / (x + 1);
	matrix_map -> map = ft_into_matrix(map, x, y);
	matrix_map -> square_size = 0;
	return (matrix_map);
}
