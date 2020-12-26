/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:02:38 by shong             #+#    #+#             */
/*   Updated: 2020/12/26 19:11:09 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;
	size_t			i;

	if (!dst && !src)
		return (0);
	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_p[i] = src_p[i];
		i++;
	}
	return (dst);
}
