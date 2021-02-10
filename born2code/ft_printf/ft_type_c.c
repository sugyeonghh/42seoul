/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:38:52 by shong             #+#    #+#             */
/*   Updated: 2021/02/10 08:38:51 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_result_c(char *ch, t_flag *flags)
{
	char	*res;
	char	*space;

	if (flags->width <= 1)
		return (ch);
	space = ft_str_filled_with(' ', flags->width - 1);
	if (flags->minus)
		res = ft_strjoin(ch, space);
	else
		res = ft_strjoin(space, ch);
	free(ch);
	free(space);
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
