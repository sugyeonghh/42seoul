/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 02:20:06 by shong             #+#    #+#             */
/*   Updated: 2020/12/25 03:32:09 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		idx;

	if (!s1 || !set)
		return (0);
	if (!ft_strlen(set))
		return (ft_strdup(""));
	while (*s1 == ' ' || *s1 == '\t' || *s1 == '\n')
		s1++;
	i = 0;
	idx = 0;
	while (s1[i])
	{
		if (s1[i] == *set)
			if (!ft_memcmp(s1 + i, set, ft_strlen(set)))
				idx += ft_strlen(set);
		res[idx++] = s1[i++];
	}
	res[idx] = 0;
	return (res);
}