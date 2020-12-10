/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_3_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjikim <eunjikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:37:34 by snpark            #+#    #+#             */
/*   Updated: 2020/11/29 13:27:19 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern char	g_line_1[8];
extern char	g_line_2[8];
extern char	g_full_map[4][4][4];
extern char	g_result_map[4][4];

void		ft_mapof_3_2(char map_3[4][4])
{
	map_3[0][0] = 1;
	map_3[0][1] = 1;
	map_3[0][2] = 0;
	map_3[0][3] = 0;
	map_3[1][0] = 0;
	map_3[1][1] = 1;
	map_3[1][2] = 1;
	map_3[1][3] = 0;
	map_3[2][0] = 0;
	map_3[2][1] = 0;
	map_3[2][2] = 0;
	map_3[2][3] = 1;
	map_3[3][0] = 1;
	map_3[3][1] = 1;
	map_3[3][2] = 1;
	map_3[3][3] = 0;
}

void		ft_punching_3_2(char map[4][4], int i, int j, int k)
{
	if (g_line_1[i] == '3' && g_line_2[i] == '2')
	{
		if (map[j][k] == 0)
		{
			if (i >= 4)
				g_full_map[j][i - 4][k] = 0;
			else
				g_full_map[i][j][k] = 0;
		}
	}
	else if (g_line_1[i] == '2' && g_line_2[i] == '3')
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

void		ft_mapping_3_2(void)
{
	int		i;
	int		j;
	int		k;
	char	map_3[4][4];

	ft_mapof_3_2(map_3);
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 4)
		{
			if (g_line_1[i] == '3' || g_line_2[i] == '3')
			{
				k = 0;
				while (k < 4)
				{
					ft_punching_3_2(map_3, i, j, k);
					k++;
				}
			}
			j++;
		}
		i++;
	}
}
