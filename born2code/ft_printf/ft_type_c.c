/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:38:52 by shong             #+#    #+#             */
/*   Updated: 2021/02/09 16:07:25 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_c(va_list ap, t_flag *flags)
{
	
	
	ft_putchar_fd(va_arg(ap, int), 1);
	





	return (1);
}
