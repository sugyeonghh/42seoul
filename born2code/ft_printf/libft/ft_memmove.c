/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:09:23 by shong             #+#    #+#             */
/*   Updated: 2020/12/30 05:48:36 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;

	if ((!dst && !src) || (dst == src))
		return (0);
	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	if (src_p > dst_p)
		return (ft_memcpy(dst, src, len));
	while (len--)
		dst_p[len] = src_p[len];
	return (dst);
}
