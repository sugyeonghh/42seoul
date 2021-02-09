/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 02:09:43 by shong             #+#    #+#             */
/*   Updated: 2021/02/06 22:58:10 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct	t_flag
{
	int	star;
	int	dot;
	int	width;
	int	zero;
	int	minus;
	int	pre;
}				t_flag;

int		ft_printf(const char *format, ...);
int		ft_type_c(t_flag *flags, va_list ap);
int		ft_type_p(t_flag *flags, va_list ap);



#endif
