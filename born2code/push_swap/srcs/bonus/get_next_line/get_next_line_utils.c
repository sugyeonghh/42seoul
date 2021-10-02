/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:03:38 by shong             #+#    #+#             */
/*   Updated: 2021/10/02 20:10:18 by shong            ###   ########.fr       */
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

int	ft_find_newline(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*res;
	int		i;
	int		idx;

	if (!s1 || !s2)
		return (0);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (0);
	i = 0;
	idx = 0;
	while (s1[idx])
		res[i++] = s1[idx++];
	while (*s2)
		res[i++] = *s2++;
	res[i] = 0;
	free(s1);
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		len;
	int		i;

	len = ft_strlen(s1);
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
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

int	ft_separate(char **line, char **save, int rd_size)
{
	int		idx;
	char	*tmp;

	tmp = ft_strdup(*save);
	free(*save);
	idx = ft_find_newline(tmp);
	if (idx > -1)
	{
		*save = ft_strdup(tmp + idx + 1);
		tmp[idx] = 0;
		*line = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	if (!rd_size)
	{
		*line = ft_strdup(tmp);
		*save = 0;
	}
	else
		*save = ft_strdup(tmp);
	free(tmp);
	return (0);
}
