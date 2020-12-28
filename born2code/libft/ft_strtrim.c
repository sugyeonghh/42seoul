/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:52:53 by shong             #+#    #+#             */
/*   Updated: 2020/12/28 23:23:42 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isset(char c, char const *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		start;
	int		end;

	if (!s1)
		return (0);
	i = -1;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_isset(s1[++i], set))
		;
	start = i;
	i = ft_strlen(s1);
	while (ft_isset(s1[--i], set))
		;
	end = i;
	if (start > end)
		return (ft_strdup(""));
	if (!(res = malloc(end - start + 2)))
		return (0);
	res = ft_memcpy(res, s1 + start, end - start + 1);
	res[end - start + 1] = 0;
	return (res);
}
