/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:03:41 by shong             #+#    #+#             */
/*   Updated: 2021/01/26 18:14:30 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*save;
	char		*tmp;
	int			rd_size;
	int			is_sep;

	if (!BUFFER_SIZE)
		return (-1);
	while ((rd_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_size] = 0;
		if (!save)
			tmp = ft_strdup(buf);
		else
			tmp = ft_strjoin(save, buf);
		if (!tmp)
			return (-1);
		is_sep = ft_separate(line, &save, tmp);
		free(tmp);
		if (is_sep)
			return (is_sep);
	}
	return (0);
}
