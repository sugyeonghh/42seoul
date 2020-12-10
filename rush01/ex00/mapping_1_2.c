/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_1_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjikim <eunjikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 23:38:29 by snpark            #+#    #+#             */
/*   Updated: 2020/11/29 13:25:54 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern char	g_line_1[8];
extern char	g_line_2[8];
extern char	g_full_map[4][4][4];
extern char	g_result_map[4][4];

void		ft_mapof_1_2(char map_1_2[4][4])
{
	map_1_2[0][0] = 0;
	map_1_2[0][1] = 0;
	map_1_2[0][2] = 0;
	map_1_2[0][3] = 1;
	map_1_2[1][0] = 1;
	map_1_2[1][1] = 1;
	map_1_2[1][2] = 0;
	map_1_2[1][3] = 0;
	map_1_2[2][0] = 1;
	map_1_2[2][1] = 1;
	map_1_2[2][2] = 0;
	map_1_2[2][3] = 0;
	map_1_2[3][0] = 0;
	map_1_2[3][1] = 0;
	map_1_2[3][2] = 1;
	map_1_2[3][3] = 0;
}

void		ft_punching_1_2(char map[4][4], int i, int j, int k)
{
	if (g_line_1[i] == '1' && g_line_2[i] == '2')
	{
		if (map[j][k] == 0)
		{
			if (i >= 4)
				g_full_map[j][i - 4][k] = 0;
			else
				g_full_map[i][j][k] = 0;
		}
	}
	else if (g_line_1[i] == '2' && g_line_2[i] == '1')
	{
		if (map[j][k] == 0)
		{
			if (i >= 4)
				g_full_map[3 - j][i - 4][k] = 0;
			else
				g_full_map[i][3 - j][k] = 0;
		}
	}
}

void		ft_mapping_1_2(void)
{
	int		i;
	int		j;
	int		k;
	char	map_1_2[4][4];

	ft_mapof_1_2(map_1_2);
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 4)
		{
			if (g_line_1[i] == '1' || g_line_2[i] == '1')
			{
				k = 0;
				while (k < 4)
				{
					ft_punching_1_2(map_1_2, i, j, k);
					k++;
				}
			}
			j++;
		}
		i++;
	}
}
