/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:17:28 by shong             #+#    #+#             */
/*   Updated: 2021/01/04 23:29:24 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2, int len)
{
	char	*res;
	int		i;
	int		j;

	if (!s1)
		s1 = "";
	res = malloc(ft_strlen(s1) + len + 1);
	i = 0;
	j = 0;
	while (*s1)
		res[i++] = *s1++;
	while (j < len)
		res[i++] = s2[j++];
	res[i] = 0;
	return (res);
}

int		ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*p = 0;
		p++;
		i++;
	}
}
