/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:26:55 by shong             #+#    #+#             */
/*   Updated: 2021/06/13 17:17:45 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft/libft.h"

# define FILE_1	1
# define FILE_2	4
# define CMD_1	2
# define CMD_2	3

typedef	struct	s_cmd
{
	const char		*cmd[5];
	char * const	*argv;
	char * const	*envp;
}				t_cmd;

void			cmd_init(const char *command, t_cmd *cmd);
void			run_cmd(const char *command);
void			connect_pipe(int *pipefd, int fd);
int				redirect_in(const char *file);
int				redirect_out(const char *file);

#endif
