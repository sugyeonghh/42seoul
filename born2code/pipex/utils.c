/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:49:42 by shong             #+#    #+#             */
/*   Updated: 2021/06/19 13:00:44 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_init(const char *command, t_cmd *cmd)
{
	char	**block;

	block = ft_split(command, ' ');
	cmd->cmd[0] = ft_strjoin("/usr/local/bin/", block[0]);
	cmd->cmd[1] = ft_strjoin("/usr/bin/", block[0]);
	cmd->cmd[2] = ft_strjoin("/bin/", block[0]);
	cmd->cmd[3] = ft_strjoin("/usr/sbin/", block[0]);
	cmd->cmd[4] = ft_strjoin("/sbin/", block[0]);
	cmd->argv = (char *const *)block;
	cmd->envp = NULL;
}

void	run_cmd(const char *command)
{
	int		i;
	t_cmd	cmd;

	cmd_init(command, &cmd);
	i = 0;
	while (i < 5)
		execve(cmd.cmd[i++], cmd.argv, cmd.envp);
	perror(cmd.argv[0]);
}

void	connect_pipe(int *pipefd, int fd)
{
	dup2(pipefd[fd], fd);
	close(pipefd[0]);
	close(pipefd[1]);
}

int		redirect_in(const char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		perror(file);
		exit(-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int		redirect_out(const char *file)
{
	int		fd;

	if ((fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0)
	{
		perror(file);
		exit(-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}
