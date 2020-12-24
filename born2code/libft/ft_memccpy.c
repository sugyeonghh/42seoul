/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 13:27:46 by shong             #+#    #+#             */
/*   Updated: 2020/12/24 18:07:19 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;
	size_t			i;

	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	if (dst == src)
		return (0);
	i = 0;
	while (i < n)
	{
		dst_p[i] = src_p[i];
		if (!src_p[i])
			break ;
		if (src_p[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
