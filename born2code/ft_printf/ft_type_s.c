/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:54:01 by shong             #+#    #+#             */
/*   Updated: 2021/02/17 06:31:22 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_result_s(char *str, t_flag *flags)
{
	char	*res;
	char	*expand;

	if (flags->dot && !flags->prec)
	{
		if (!flags->width)
			return (ft_strdup(""));
		else
			return (ft_str_filled_with(' ', flags->width));
	}
	if (flags->width <= (int)ft_strlen(str))
		return (str);
	if (flags->zero && !flags->prec && ft_strlen(str))
		expand = ft_str_filled_with('0', flags->width - (int)ft_strlen(str));
	else
		expand = ft_str_filled_with(' ', flags->width - (int)ft_strlen(str));
	if (flags->minus)
		res = ft_strjoin(str, expand);
	else
		res = ft_strjoin(expand, str);
	free(str);
	free(expand);
	return (res);
}

static char	*ft_get_str(const char *s, t_flag *flags)
{
	char	*str;

	if (!s)
	{
		free((char *)s);
		s = ft_strdup("(null)");
	}
	if (!(flags->prec) || flags->prec >= (int)ft_strlen(s))
		return (ft_get_result_s(ft_strdup(s), flags));
	str = (char *)malloc(sizeof(char) * flags->prec + 1);
	ft_strlcpy(str, s, flags->prec + 1);
	return (ft_get_result_s(str, flags));
}

int			ft_type_s(const char *s, t_flag *flags)
{
	char	*res;
	int		res_size;

	res = ft_get_str(s, flags);
	res_size = ft_strlen(res);
	write(1, res, res_size);
	free(res);
	return (res_size);
}
