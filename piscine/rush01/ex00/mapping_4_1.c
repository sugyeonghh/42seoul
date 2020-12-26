/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_4_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjikim <eunjikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:37:34 by snpark            #+#    #+#             */
/*   Updated: 2020/11/29 15:27:36 by eunjikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern char	g_line_1[8];
extern char	g_line_2[8];
extern char	g_full_map[4][4][4];
extern char	g_result_map[4][4];

void		ft_mapof_4_1(char map_4[4][4])
{
	map_4[0][0] = 1;
	map_4[0][1] = 0;
	map_4[0][2] = 0;
	map_4[0][3] = 0;
	map_4[1][0] = 0;
	map_4[1][1] = 1;
	map_4[1][2] = 0;
	map_4[1][3] = 0;
	map_4[2][0] = 0;
	map_4[2][1] = 0;
	map_4[2][2] = 1;
	map_4[2][3] = 0;
	map_4[3][0] = 0;
	map_4[3][1] = 0;
	map_4[3][2] = 0;
	map_4[3][3] = 1;
}

void		ft_punching_4_1(char map[4][4], int i, int j, int k)
{
	if (g_line_1[i] == '4' && g_line_2[i] == '1')
	{
		if (map[j][k] == 0)
		{
			if (i >= 4)
				g_full_map[j][i - 4][k] = 0;
			else
				g_full_map[i][j][k] = 0;
		}
	}
	else if (g_line_1[i] == '1' && g_line_2[i] == '4')
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

void		ft_mapping_4_1(void)
{
	int		i;
	int		j;
	int		k;
	char	map_4[4][4];

	ft_mapof_4_1(map_4);
	i = 0;
	while (i < 8)
	{
		j = 0;
		if (g_line_1[i] == '4' || g_line_2[i] == '4')
		{
			while (j < 4)
			{
				k = 0;
				while (k < 4)
				{
					ft_punching_4_1(map_4, i, j, k);
					k++;
				}
				j++;
			}
		}
		i++;
	}
}