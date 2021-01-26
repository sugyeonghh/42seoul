/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:03:38 by shong             #+#    #+#             */
/*   Updated: 2021/01/26 18:13:15 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int		ft_strchr_idx(const char *s, const char c)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	if (!s1 || !s2)
		return (0);
	if (!(res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	i = 0;
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i] = 0;
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		len;
	int		i;

	len = ft_strlen(s1);
	if (!(tmp = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

int		ft_separate(char **line, char **save, char *tmp)
{
	int		idx;

	while (*tmp == '\n')
		tmp++;
	if ((idx = ft_strchr_idx(tmp, '\n')) > -1)
	{
		if (!(*save = ft_strdup(tmp + idx)))
			return (-1);
		tmp[idx] = 0;
		if (!(*line = ft_strdup(tmp)))
			return (-1);
		return (1);
	}
	if (!(*save = ft_strdup(tmp)))
		return (-1);
	return (0);
}
