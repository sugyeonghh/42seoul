/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjikim <eunjikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:12:07 by shong             #+#    #+#             */
/*   Updated: 2020/11/29 22:54:15 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initial.h"
#include "libft.h"
#include "error.h"
#include "mapping.h"
#include "check.h"

char	g_line_1[8];
char	g_line_2[8];
char	g_full_map[4][4][4];
char	g_result_map[4][4];

int			main(int argc, char **argv)
{
	if (argc != 2 || ft_strlen(argv[1]) != 31)
	{
		ft_print_error();
		return (0);
	}
	ft_initial(argv, g_line_1, g_line_2);
	if (((ft_valid_number(g_line_1) || (ft_valid_number(g_line_2)))))
	{
		ft_print_error();
		return (0);
	}
	if (!ft_check_sight(g_line_1, g_line_2))
	{
		ft_print_error();
		return (0);
	}
	ft_inital_map(g_full_map, g_result_map);
	ft_mapping();
	ft_fm_re();
	ft_remapping();
	ft_print_result(g_result_map);
}
