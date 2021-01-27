/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:03:41 by shong             #+#    #+#             */
/*   Updated: 2021/01/27 23:01:49 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 2560
# endif

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
int		ft_find_newline(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		ft_separate(char **line, char **save, int rd_size);

#endif
