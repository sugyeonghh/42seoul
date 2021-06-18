/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:41:34 by shong             #+#    #+#             */
/*   Updated: 2021/06/15 19:14:12 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h> 
# include <stdio.h>
# include <sys/wait.h>
# include "libft/libft.h"


typedef struct	s_cmd
{
	const char		*cmd[5];
	char * const	*argv;
	char * const	*envp;
}				t_cmd;

void	cmd_init(const char *command, t_cmd *cmd);
void	run_cmd(const char *command);

#endif
