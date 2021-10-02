/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:58:56 by shong             #+#    #+#             */
/*   Updated: 2021/06/19 14:20:53 by shong            ###   ########.fr       */
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
		redirect_in(argv[1]);
		connect_pipe(pipefd, STDOUT_FILENO);
		run_cmd(argv[2]);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) == 0)
			exit(-1);
		redirect_out(argv[4]);
		connect_pipe(pipefd, STDIN_FILENO);
		run_cmd(argv[3]);
	}
	return (0);
}
