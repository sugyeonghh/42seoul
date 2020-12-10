/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjikim <eunjikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:05:00 by snpark            #+#    #+#             */
/*   Updated: 2020/11/29 23:20:12 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_result.h"
#include "check_2.h"

extern char	g_full_map[4][4][4];
extern char	g_result_map[4][4];

int		ft_check_legal(int x, int y)
{
	int i;
	int idx;
	int count;

	i = 0;
	idx = 0;
	count = 0;
	while (i <= 3)
	{
		if (g_full_map[x][y][i] == 1)
		{
			count++;
			idx = i;
		}
		i++;
	}
	if (count == 1)
		return (idx);
	else if (count == 0)
		return (idx);
	else
		idx = -1;
	return (idx);
}

void	ft_fm_re(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			g_result_map[i][j] = ft_check_legal(i, j);
			j++;
		}
		i++;
	}
}

void	ft_is_negative(int i, int j)
{
	int k;

	k = 0;
	while (k <= 3)
	{
		if (g_result_map[i][k] != -1)
			g_full_map[i][j][(int)g_result_map[i][k]] = 0;
		if (g_result_map[k][j] != -1)
			g_full_map[i][j][(int)g_result_map[k][j]] = 0;
		k++;
	}
	g_result_map[i][j] = ft_check_legal(i, j);
}

void	ft_is_3(int i, int j)
{
	int k;
	int count;

	count = 0;
	if (g_full_map[i][j][2] == 1)
	{
		k = 0;
		while (k <= 3)
		{
			if (g_full_map[i][k][2] == 1 || g_full_map[k][j][2] == 1)
				count++;
			k++;
		}
	}
	if (count == 2)
	{
		k = 0;
		while (k <= 3)
		{
			if (k != 2)
				g_full_map[i][j][k] = 0;
			k++;
		}
	}
}

void	ft_remapping(void)
{
	int i;
	int j;

	while (ft_check_result() == -1)
	{
		i = 0;
		while (i <= 3)
		{
			j = 0;
			while (j <= 3)
			{
				if (g_result_map[i][j] == -1)
				{
					ft_is_negative(i, j);
					ft_is_3(i, j);
				}
				j++;
			}
			i++;
		}
		ft_check_2();
	}
}
