/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:12:28 by shong             #+#    #+#             */
/*   Updated: 2020/12/22 16:25:13 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == 0)
		return (haystack);
	i = 0;
	while (haystack[i] != 0)
	{
		if (haystack[i] == *needle)
			if(ft_strncmp(haystack + i, needle, len) == 0)
				return (haystack + i);
		i++;
	}
	return (0);
}
