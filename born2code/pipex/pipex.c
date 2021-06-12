/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:58:56 by shong             #+#    #+#             */
/*   Updated: 2021/06/12 19:52:50 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		main(int argc, char *argv[])
{
	int		pipefd[2];
	int		status;
	t_cmd	cmd;
	pid_t	pid;

	if (argc != 5)
		return (0);
	pipe(pipefd);
	pid = fork();
	if (pid > 0)
	{
		waitpid(pid, &status, 0);
		redirect_out(FILE_2);
		connect_pipe(pipefd, 0);
		cmd_init(CMD_2, &cmd);
		if (execve(cmd.cmd, cmd.argv, cmd.envp) == -1)
			perror(cmd.cmd);
	}
	else if (pid == 0)
	{
		redirect_in(FILE_1);
		connect_pipe(pipefd, 1);
		cmd_init(CMD_1, &cmd);
		if (execve(cmd.cmd, cmd.argv, cmd.envp) == -1)
			perror(cmd.cmd);
	}
	return (0);
}
