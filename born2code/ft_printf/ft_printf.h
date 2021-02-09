/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 02:09:43 by shong             #+#    #+#             */
/*   Updated: 2021/02/09 16:06:25 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct	t_flag
{
	int	minus;
	int	zero;
	int	dot;
	int	star;
	int	width;
	int	prec;
}				t_flag;

int		ft_printf(const char *format, ...);
int		ft_type_c(va_list ap, t_flag *flags);
int		ft_type_s(va_list ap, t_flag *flags);
int		ft_type_p(va_list ap, t_flag *flags);
int		ft_type_num(va_list ap, t_flag *flags);
int		ft_type_mod(va_list ap, t_flag *flags);


#endif
