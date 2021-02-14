/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 02:09:43 by shong             #+#    #+#             */
/*   Updated: 2021/02/15 00:30:36 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	t_flag
{
	int	minus;
	int	zero;
	int	dot;
	int	width;
	int	prec;
}				t_flag;

int		ft_printf(const char *format, ...);
int		ft_print_type(char **format, va_list ap);
char	*ft_str_filled_with(char c, int len);
int		ft_type_c(const char c, t_flag *flags);
int		ft_type_s(const char *s, t_flag *flags);
int		ft_type_p(unsigned long long nbr, t_flag *flags);
int		ft_type_di(int nbr, t_flag *flags);
int		ft_type_uxX(const char format, unsigned int nbr, t_flag *flags);


#endif
