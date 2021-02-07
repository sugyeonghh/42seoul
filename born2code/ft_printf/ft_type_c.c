/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:47:31 by shong             #+#    #+#             */
/*   Updated: 2021/02/07 23:07:28 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_c(t_flag *flags, va_list ap)
{
	int	size;

	if (!(flags->width) && flags->star)
		flags->width = va_arg(ap, int);
	size = flags->width;
	if (!(flags->minus))
	{
		while (size-- > 1)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(va_arg(ap, int), 1);
	}
	else
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		while (size-- > 1)
			ft_putchar_fd(' ', 1);
	}
	return (flags->width);
}
