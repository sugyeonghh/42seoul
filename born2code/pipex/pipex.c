/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:58:56 by shong             #+#    #+#             */
/*   Updated: 2021/06/13 17:16:23 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		main(int argc, char *argv[])
{
	int		pipefd[2];
	int		status;
	pid_t	pid;

	if (argc != 5)
		return (0);
	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		redirect_in(argv[FILE_1]);
		connect_pipe(pipefd, STDOUT_FILENO);
		run_cmd(argv[CMD_1]);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		redirect_out(argv[FILE_2]);
		connect_pipe(pipefd, STDIN_FILENO);
		run_cmd(argv[CMD_2]);
	}
	return (0);
}
