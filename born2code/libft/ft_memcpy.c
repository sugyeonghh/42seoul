/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:02:38 by shong             #+#    #+#             */
/*   Updated: 2020/12/22 23:01:14 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_p;
	char	*src_p;
	size_t	i;

	dst_p = (char *)dst;
	src_p = (char *)src;
	if (dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		dst_p[i] = src_p[i];
		i++;
	}
	return (dst);
}