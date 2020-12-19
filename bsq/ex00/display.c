/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sook-yeon <sook-yeon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:50:35 by sook-yeon         #+#    #+#             */
/*   Updated: 2020/12/20 02:53:02 by sook-yeon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "s_map.h"

void	ft_display(s_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map -> map[i][j] != 0)
	{
		j = 0;
		while (map -> map[i][j] != 0)
		{
			write(1, &(map -> map[i][j]), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

