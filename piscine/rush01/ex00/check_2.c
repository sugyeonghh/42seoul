/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:40:50 by snpark            #+#    #+#             */
/*   Updated: 2020/11/29 23:24:50 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern char	g_line_1[8];
extern char	g_line_2[8];
extern char	g_full_map[4][4][4];
extern char	g_result_map[4][4];

int		ft_check_12(int i, int j)
{
	int count;
	int k;
	int err;

	k = 0;
	count = 0;
	err = 0;
	while (k <= 3)
	{
		if (g_full_map[i][j][k] == 1)
			err++;
		k++;
	}
	if (g_full_map[i][j][0] == 1 && g_full_map[i][j][1] == 1 && err == 2)
		count = 1;
	if (g_full_map[i][j][2] == 1 && err == 1)
		count = 2;
	if (g_full_map[i][j][3] == 1 && err == 1)
		count = 3;
	return (count);
}

int		ft_iso(void)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (ft_check_12(i, j) == 1 && i % 2 == 1 && j % 2 == 1)
				if (ft_check_12(i + 1, j + 1) == 1)
					count++;
			if (ft_check_12(i, j) == 1 && i % 2 == 0 && j % 2 == 1)
				if (ft_check_12(i - 1, j + 1) == 1)
					count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_punch_12(int i, int j, int mod)
{
	int k;

	k = 0;
	while (k <= 1)
	{
		if (mod == 120)
		{
			if (i < 4)
				g_full_map[i][j + k][k] = 0;
			else if (i >= 4)
				g_full_map[j + k][i - 4][k] = 0;
		}
		else if (mod == 210)
		{
			if (i < 4)
				g_full_map[i][j + k][1 - k] = 0;
			else if (i >= 4)
				g_full_map[j + k][i - 4][1 - k] = 0;
		}
	}
}

void	ft_sight_x(void)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (ft_check_12(i, 0) == 1 && ft_check_12(i, 1) == 1)
		{
			if (g_line_1[i] == 3 && ft_check_12(i, 2) == 2)
				ft_punch_12(i, 0, 210);
			else
				ft_punch_12(i, 0, 120);
		}
		else if (ft_check_12(i, 3) == 1 && ft_check_12(i, 2) == 1)
		{
			if (g_line_2[i] == 3 && ft_check_12(i, 1) == 2)
				ft_punch_12(i, 2, 120);
			else
				ft_punch_12(i, 2, 210);
		}
		i++;
	}
}

void	ft_sight_y(void)
{
	int i;

	i = 4;
	while (i <= 7)
	{
		if (ft_check_12(0, i) == 1 && ft_check_12(1, i) == 1)
		{
			if (g_line_1[i] == 3 && ft_check_12(2, i) == 2)
				ft_punch_12(0, i, 210);
			else
				ft_punch_12(0, i, 120);
		}
		else if (ft_check_12(3, i) == 1 && ft_check_12(2, i) == 1)
		{
			if (g_line_2[i] == 3 && ft_check_12(1, i) == 2)
				ft_punch_12(2, i, 120);
			else
				ft_punch_12(2, i, 120);
		}
		i++;
	}
}
