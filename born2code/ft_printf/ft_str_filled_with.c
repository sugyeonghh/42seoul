/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_filled_with.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 04:15:51 by shong             #+#    #+#             */
/*   Updated: 2021/02/15 01:07:32 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_filled_with(char c, int len)
{
	char	*str;

	if (len < 0)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * len + 1);
	ft_memset(str, c, len);
	str[len] = 0;
	return (str);
}
