/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sook-yeon <sook-yeon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:50:54 by sook-yeon         #+#    #+#             */
/*   Updated: 2020/12/20 02:58:03 by sook-yeon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "find_square.h"
#include "display.h"

int		main(int argc, char *argv[])
{
	int		fd;
	char 	buf[1000];
	int		num;

	if (argc == 1)
	{
		printf("argv is NULL \n");
		return (0);
	}
	num = 1;
	while (num < argc)
	{
		fd = open(argv[num], O_RDONLY);
		if (fd == -1)
			return (1);
		if (read(fd, buf, sizeof(buf)) == -1)
			return (1);
		ft_display(ft_find_sqaure(buf));
		num++;
	}

}