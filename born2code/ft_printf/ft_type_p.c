/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:50:12 by shong             #+#    #+#             */
/*   Updated: 2021/02/09 01:15:16 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_p(va_list ap, t_flag *flags)
{
	flags->dot = 0;
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_ull(va_arg(ap, unsigned long long), "0123456789abcdef");

	
	
	
	
	
	
	return (0);
}