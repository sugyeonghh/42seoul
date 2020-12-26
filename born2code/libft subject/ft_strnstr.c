/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:12:28 by shong             #+#    #+#             */
/*   Updated: 2020/12/24 22:40:48 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len-- >= ft_strlen(needle))
	{
		if (*haystack == *needle)
		{
			if (!ft_memcmp(haystack, needle, ft_strlen(needle)))
				return ((char *)haystack);
		}
		haystack++;
	}
	return (0);
}
