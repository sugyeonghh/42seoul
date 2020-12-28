/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:42:39 by shong             #+#    #+#             */
/*   Updated: 2020/12/28 19:51:46 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_word_count(char const *s, char c)
{
	int		cnt;

	cnt = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			cnt++;
		while (*s && *s != c)
			s++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*tmp;
	int		i;

	if (!s || !(res = malloc(sizeof(char *) * (ft_word_count(s, c) + 1))))
		return (0);
	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			tmp = (char *)s;
			while (*s && *s != c)
				s++;
			if (!(res[i] = (char *)malloc((s - tmp + 1))))
			{
				i = 0;
				while (res[i])
					free(res[i++]);
				free(res);
				return (0);
			}
			ft_strlcpy(res[i++], tmp, s - tmp + 1);
		}
		else if (*s)
			s++;
	}
	res[i] = 0;
	return (res);
}
