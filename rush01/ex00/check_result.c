/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 21:53:13 by snpark            #+#    #+#             */
/*   Updated: 2020/11/29 23:24:09 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_2.h"

extern char g_result_map[4][4];
extern char g_full_map[4][4][4];

int		ft_check_result(void)
{
	int i;
	int j;
	int result;

	result = 0;
	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (g_result_map[i][j] == -1)
				result = -1;
			j++;
		}
		i++;
	}
	return (result);
}

void	ft_ran_fil(void)
{
	int i;
	int j;
	int stop;

	i = 0;
	stop = 0;
	while (i <= 3 && stop == 0)
	{
		j = 0;
		while (j <= 3)
		{
			if (g_full_map[i][j][0] == 1 && g_full_map[i][j][1] == 1)
			{
				g_full_map[i][j][0] = 0;
				stop++;
			}
			j++;
		}
		i++;
	}
}

void	ft_check_2(void)
{
	ft_sight_x();
	ft_sight_y();
	if (ft_iso() == 4 || ft_iso() == 2)
		ft_ran_fil();
}
