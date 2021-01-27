/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:03:41 by shong             #+#    #+#             */
/*   Updated: 2021/01/27 23:01:38 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*save[OPEN_MAX];
	int			rd_size;
	int			is_sep;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((rd_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_size] = 0;
		if (!save[fd])
			save[fd] = ft_strdup(buf);
		else
			save[fd] = ft_strjoin(save[fd], buf);
		if ((is_sep = ft_separate(line, &save[fd], rd_size)))
			return (is_sep);
	}
	if (rd_size < 0)
		return (-1);
	if (!save[fd])
		save[fd] = ft_strdup("");
	return (ft_separate(line, &save[fd], rd_size));
}
