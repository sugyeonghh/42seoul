/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:04:11 by shong             #+#    #+#             */
/*   Updated: 2021/06/14 19:25:58 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	cmd_init(const char *command, t_cmd *cmd)
{
	char	**block;

	block = ft_split(command, ' ');
	cmd->cmd[0] = ft_strjoin("/usr/local/bin/", block[0]);
	cmd->cmd[1] = ft_strjoin("/usr/bin/", block[0]);
	cmd->cmd[2] = ft_strjoin("/bin/", block[0]);
	cmd->cmd[3] = ft_strjoin("/usr/sbin/", block[0]);
	cmd->cmd[4] = ft_strjoin("/sbin/", block[0]);
	cmd->argv = (char * const *)block;
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
