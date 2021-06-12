/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:44:47 by shong             #+#    #+#             */
/*   Updated: 2021/06/12 19:51:36 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		redirect_in(const char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("can not found!");
		return (-1);
	}
	dup2(fd, 0);
	close(fd);
	return (0);
}

int		redirect_out(const char *file)
{
	int		fd;

	fd = open(file, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
	{
		perror("can not found!");
		return (-1);
	}
	dup2(fd, 1);
	close(fd);
	return (0);
}
