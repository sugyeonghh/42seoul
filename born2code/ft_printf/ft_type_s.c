/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:54:01 by shong             #+#    #+#             */
/*   Updated: 2021/02/10 08:40:02 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_result_s(char *str, t_flag *flags)
{
	char	*res;
	char	*space;

	if (flags->width <= (int)ft_strlen(str))
		return (str);
	space = ft_str_filled_with(' ', flags->width - (int)ft_strlen(str));
	if (flags->minus)
		res = ft_strjoin(str, space);
	else
		res = ft_strjoin(space, str);
	free(str);
	free(space);
	return (res);
}

static char	*ft_get_str(const char *s, t_flag *flags)
{
	char	*str;

	if (!(flags->prec) || flags->prec >= (int)ft_strlen(s))
		return (ft_get_result_s(ft_strdup(s), flags));
	str = (char *)malloc(sizeof(char) * flags->prec + 1);
	ft_strlcpy(str, s, flags->prec + 1);
	return (ft_get_result_s(str, flags));
}

int			ft_type_s(const char *s, t_flag *flags)
{
	char	*res;

	res = ft_get_str(s, flags);
	ft_putstr_fd(res, 1);
	free(res);
	return (ft_strlen(res));
}
