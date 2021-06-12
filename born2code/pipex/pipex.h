/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:26:55 by shong             #+#    #+#             */
/*   Updated: 2021/06/12 19:52:58 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef	struct	s_cmd
{
	const char		*cmd;
	char * const	*argv;
	char * const	*envp;
}				t_cmd;

# define FILE_1	argv[1]
# define FILE_2	argv[4]
# define CMD_1	argv[2]
# define CMD_2	argv[3]


int		redirect_in(const char *file);
int		redirect_out(const char *file);
void	cmd_init(const char *cmd, t_cmd *strt);
void	connect_pipe(int pipefd[2], int io);

#endif
