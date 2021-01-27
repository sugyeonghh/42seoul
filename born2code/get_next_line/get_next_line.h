/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:03:41 by shong             #+#    #+#             */
/*   Updated: 2021/01/27 21:42:00 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
int		ft_find_newline(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		ft_separate(char **line, char **save, int rd_size);

#endif