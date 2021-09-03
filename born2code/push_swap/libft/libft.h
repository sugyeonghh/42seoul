/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:32:35 by shong             #+#    #+#             */
/*   Updated: 2021/09/04 03:47:58 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_isdigit(int c);
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *s, size_t n);
char				**ft_split(char const *s, char c);
void				ft_putstr_fd(char *s, int fd);

#endif
