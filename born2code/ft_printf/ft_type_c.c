/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 03:56:50 by shong             #+#    #+#             */
/*   Updated: 2021/02/19 12:29:57 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_result_c(char *ch, t_flag *flags)
{
	char	*res;
	char	*expand;

	if (flags->width <= 1)
		return (ch);
	if (flags->zero)
		expand = ft_str_filled_with('0', flags->width - 1);
	else
		expand = ft_str_filled_with(' ', flags->width - 1);
	res = (char *)malloc(sizeof(char) * flags->width + 1);
	if (flags->minus)
	{
		ft_memcpy(res, ch, 1);
		ft_memcpy(res + 1, expand, ft_strlen(expand));
	}
	else
	{
		ft_memcpy(res, expand, ft_strlen(expand));
		ft_memcpy(res + ft_strlen(expand), ch, 1);
	}
	res[flags->width] = 0;
	free(ch);
	free(expand);
	return (res);
}

static char	*ft_get_char(const char c, t_flag *flags)
{
	char	*ch;

	ch = (char *)malloc(sizeof(char) * 2);
	ch[0] = c;
	ch[1] = 0;
	return (ft_get_result_c(ch, flags));
}

int			ft_type_c(const char c, t_flag *flags)
{
	char	*res;
	int		res_size;

	res = ft_get_char(c, flags);
	res_size = ft_strlen(res);
	if (!c)
	{
		if (flags->width)
			res_size = flags->width;
		else
			res_size = 1;
	}
	write(1, res, res_size);
	free(res);
	return (res_size);
}
