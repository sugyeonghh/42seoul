/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:08:38 by shong             #+#    #+#             */
/*   Updated: 2020/12/28 20:13:56 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t dst_len;
	size_t src_len;

	i = 0;
	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	else if (dstsize <= ft_strlen(dst))
		return (src_len + dstsize);
	else
	{
		if (dstsize - 1 > 0)
		{
			while (dst[i] != 0)
				i++;
			while (src[j] != 0 && j < dstsize - dst_len - 1)
				dst[i++] = src[j++];
			dst[i] = 0;
		}
		return (src_len + dst_len);
	}
}
