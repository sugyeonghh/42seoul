/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 02:44:05 by shong             #+#    #+#             */
/*   Updated: 2021/06/20 03:34:30 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_argv_error(int argc, char *argv[])
{
	int		i;
	int		j;

	if (argc <= 1)
		return (-1);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
			if (ft_isalpha(argv[i][j++]))
				return (-1);
		i++;
	}
	return (0);
}

int		check_integer_error(int argc, char *argv[])
{
		
}
