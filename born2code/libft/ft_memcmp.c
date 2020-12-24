/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:28:57 by shong             #+#    #+#             */
/*   Updated: 2020/12/24 18:57:51 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	i = 0;
	if ((p1 == p2) || !n)
		return (0);
	while (p1[i] == p2[i] && i < n - 1)
		i++;
	return ((int)(p1[i] - p2[i]));	
}