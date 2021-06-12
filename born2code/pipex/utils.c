/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:49:42 by shong             #+#    #+#             */
/*   Updated: 2021/06/12 19:51:44 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_init(const char *cmd, t_cmd *strt)
{
	char	**block;

	block = ft_split(cmd, ' ');
	strt->cmd = ft_strjoin("/bin/", block[0]);
	strt->argv = (char *const *)block;
	strt->envp = NULL;
}

void	connect_pipe(int pipefd[2], int io)
{
	dup2(pipefd[io], io);
	close(pipefd[0]);
	close(pipefd[1]);
}
