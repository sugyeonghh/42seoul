/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:04:47 by shong             #+#    #+#             */
/*   Updated: 2021/02/15 18:55:45 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_result_di(char *nbr_di, t_flag *flags)
{
	char	*res;
	char	*expand;

	if (flags->width <= (int)ft_strlen(nbr_di))
		return (nbr_di);
	if (flags->zero && !flags->minus && !flags->prec)
		expand = ft_str_filled_with('0', flags->width - (int)ft_strlen(nbr_di));
	else
		expand = ft_str_filled_with(' ', flags->width - (int)ft_strlen(nbr_di));
	if (flags->minus)
		res = ft_strjoin(nbr_di, expand);
	else
		res = ft_strjoin(expand, nbr_di);
	free(nbr_di);
	free(expand);
	return (res);
}

static char	*ft_get_nbr_di(int nbr, t_flag *flags)
{
	char	*nbr_di;
	char	*zero;
	char	*nbr_di_prec;
	
	if (flags->dot && !flags->prec && !nbr)
		return (ft_get_result_di(ft_strdup(""), flags));
	nbr_di = ft_itoa(nbr);
	if (flags->prec <= (int)ft_strlen(nbr_di))
		return (ft_get_result_di(nbr_di, flags));
	zero = ft_str_filled_with('0', flags->prec - (int)ft_strlen(nbr_di));
	nbr_di_prec = ft_strjoin(zero, nbr_di);
	free(nbr_di);
	free(zero);
	return (ft_get_result_di(nbr_di_prec, flags));
}

int			ft_type_di(int nbr, t_flag *flags)
{
	char	*res;
	int		res_size;

	res = ft_get_nbr_di(nbr, flags);
	res_size = ft_strlen(res);
	write(1, res, res_size);
	free(res);
	return (res_size);
}
