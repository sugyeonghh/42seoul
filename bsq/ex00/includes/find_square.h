/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sook-yeon <sook-yeon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:50:43 by sook-yeon         #+#    #+#             */
/*   Updated: 2020/12/20 02:15:51 by sook-yeon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_SQUARE_H
# define FIND_SQUARE_H

#include "s_map.h"

int		ft_sqrt(int nb);
void	ft_fill_x(s_map *map, int x, int y, int size);
s_map	*ft_find_ox(s_map *map, int x, int y);
s_map	*ft_find_sqaure(char *map);

#endif