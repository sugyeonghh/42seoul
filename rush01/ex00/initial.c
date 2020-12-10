/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjikim <eunjikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:45:59 by eunjikim          #+#    #+#             */
/*   Updated: 2020/11/29 21:30:58 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"

extern char	g_line_1[8];
extern char	g_line_2[8];
extern char	g_full_map[4][4][4];
extern char	g_result_map[4][4];

int		ft_valid_number(char *line)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < 8)
	{
		if (!(line[i] >= '1' && line[i] <= '4'))
		{
			flag = 1;
			break ;
		}
		i++;
	}
	return (flag);
}

void	ft_initial(char **argv, char *line_1, char *line_2)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 32)
	{
		if (i % 16 < 8)
		{
			if (argv[1][i] >= '1' && argv[1][i] <= '4')
				line_1[j++] = argv[1][i];
		}
		else
		{
			if (argv[1][i] >= '1' && argv[1][i] <= '4')
				line_2[k++] = argv[1][i];
		}
		i += 2;
	}
}

int		ft_check_sight(char *line_1, char *line_2)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (i < 8)
	{
		flag = 0;
		if ((line_1[i] == line_2[i]) && (line_1[i] != '2'))
			break ;
		else if ((line_1[i] == '4' && line_2[i] == '3'))
			break ;
		else if ((line_1[i] == '4' && line_2[i] == '2'))
			break ;
		else if ((line_1[i] == '2' && line_2[i] == '4'))
			break ;
		else if ((line_1[i] == '3' && line_2[i] == '4'))
			break ;
		else
			flag = 1;
		i++;
	}
	return (flag);
}

void	ft_inital_map(char full_map[4][4][4], char result_map[4][4])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
				full_map[i][j][k++] = 1;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			result_map[i][j++] = -1;
		i++;
	}
}
