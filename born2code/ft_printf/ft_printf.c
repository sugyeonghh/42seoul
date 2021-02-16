/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:17:16 by shong             #+#    #+#             */
/*   Updated: 2021/02/17 01:41:19 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			size;
	char		*tmp;

	size = 0;
	tmp = ft_strdup(format);
	va_start(ap, format);
	while (*tmp)
	{
		if (*tmp == '%' &&
				(ft_strchr("cspdiuxX%-0.*", *(++tmp)) || ft_isdigit(*tmp)))
			size += ft_print_type(&tmp, ap);
		else
		{
			ft_putchar_fd(*tmp, 1);
			size++;
		}
		tmp++;
	}
	va_end(ap);
	free(tmp - ft_strlen(format));
	return (size);
}
