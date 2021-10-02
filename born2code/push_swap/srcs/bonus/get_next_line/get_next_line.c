/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:03:41 by shong             #+#    #+#             */
/*   Updated: 2021/10/02 20:43:00 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*save;
	int			rd_size;
	int			is_sep;

	exception(fd, line);
	while (1)
	{
		rd_size = read(fd, buf, BUFFER_SIZE);
		if (rd_size <= 0)
			break ;
		buf[rd_size] = 0;
		if (!save)
			save = ft_strdup(buf);
		else
			save = ft_strjoin(save, buf);
		is_sep = ft_separate(line, &save, rd_size);
		if (is_sep)
			return (is_sep);
	}
	if (rd_size < 0)
		return (-1);
	if (!save)
		save = ft_strdup("");
	return (ft_separate(line, &save, rd_size));
}

void	exception(int fd, char **line)
{
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		exit(-1);
}
