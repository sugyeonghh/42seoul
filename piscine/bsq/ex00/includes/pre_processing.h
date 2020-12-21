/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_processing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sook-yeon <sook-yeon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:51:06 by sook-yeon         #+#    #+#             */
/*   Updated: 2020/12/14 23:12:55 by sook-yeon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRE_PROCESSING_H
# define PRE_PROCESSING_H

#include "s_map.h"

char	**ft_into_matrix(char *map, int x, int y);
s_map	*ft_pre_process(char *map);

#endif