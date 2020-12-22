/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:49:21 by shong             #+#    #+#             */
/*   Updated: 2020/12/22 16:59:42 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = ft_strlen(s);
	if (c == 0)
		return ((char *)s + i);
	while (i--)
		if (s[i] == c)
			return ((char *)s + i);
	return (0);
}
