/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjikim <eunjikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:37:34 by snpark            #+#    #+#             */
/*   Updated: 2020/11/29 15:31:44 by eunjikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapping_4_1.h"
#include "mapping_1_2.h"
#include "mapping_2_2.h"
#include "mapping_1_3.h"
#include "mapping_3_2.h"

extern char	g_line_1[8];
extern char	g_line_2[8];
extern char	g_full_map[4][4][4];
extern char	g_result_map[4][4];

void		ft_mapping(void)
{
	ft_mapping_4_1();
	ft_mapping_1_2();
	ft_mapping_1_3();
	ft_mapping_3_2();
	ft_mapping_2_2();
}
