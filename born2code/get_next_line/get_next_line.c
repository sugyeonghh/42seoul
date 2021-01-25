/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:14:55 by shong             #+#    #+#             */
/*   Updated: 2021/01/25 14:08:15 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*tmp;
	int				idx;
	int				isread;

	if (BUFFER_SIZE <= 0)
		return (-1);
	ft_bzero(buf, BUFFER_SIZE);
	while ((isread = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if ((idx = ft_strchr(buf, '\n')) == -1)
			tmp = ft_strjoin(tmp, buf, isread);
		else
		{
			*line = ft_strjoin(tmp, buf, idx);
			tmp = ft_strjoin("", buf + idx + 1, BUFFER_SIZE - idx - 1);
			return (1);
		}
		ft_bzero(buf, BUFFER_SIZE);
	}
	printf("tmp: %s, buf: %s\n", tmp, buf);
	*line = ft_strjoin(tmp, buf, idx);
	return (!isread ? 0 : -1);
}

int		main(void)
{
	char *line = 0;
	int ret;
	int fd;

	fd = open("test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("line: %s\n", line);
		free(line);
	}
	printf("line: %s\n", line);
	free(line);
	return (0);
}
