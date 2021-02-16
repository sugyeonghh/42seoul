/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:04:47 by shong             #+#    #+#             */
/*   Updated: 2021/02/17 06:55:51 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_expand_with_zero(char *expand, char *nbr_di, t_flag *flags)
{
	char	*res;
	int		i;
	int		nbr_len;

	i = 0;
	nbr_len = nbr_di[i] == '-' ? ft_strlen(nbr_di) - 1 : ft_strlen(nbr_di);
	res = (char *)malloc(sizeof(char) * flags->width + 1);
//	ft_memset(res, '0', flags->width);
	if (nbr_di[i] == '-')
		res[i++] = '-';
	ft_strlcpy(res + 1, expand, ft_strlen(expand));
	ft_strlcpy(res + 1 + ft_strlen(expand), nbr_di + i, nbr_len + 1);
//	ft_strlcpy(res + flags->width - nbr_len, nbr_di + i, nbr_len + 1);
	return (res);
}

static char	*ft_get_result_di(char *nbr_di, t_flag *flags)
{
	char	*res;
	char	*expand;

	if (flags->width <= (int)ft_strlen(nbr_di))
		return (nbr_di);
	if (flags->zero && !flags->dot && !flags->minus
			&& !flags->prec && ft_strlen(nbr_di))
		expand = ft_str_filled_with('0', flags->width - (int)ft_strlen(nbr_di));
	else
		expand = ft_str_filled_with(' ', flags->width - (int)ft_strlen(nbr_di));
	if (flags->minus)
		res = ft_strjoin(nbr_di, expand);
	else if (*expand == ' ')
		res = ft_strjoin(expand, nbr_di);
	else
		res = ft_expand_with_zero(expand, nbr_di, flags);
	free(nbr_di);
	free(expand);
	return (res);
}

static char	*ft_get_nbr_di(int nbr, t_flag *flags)
{
	char	*nbr_di;
	char	*nbr_di_prec;
	int		i;
	int		nbr_len;

	if (flags->dot && !flags->prec && !nbr)
		return (ft_get_result_di(ft_strdup(""), flags));
	nbr_di = ft_itoa(nbr);
	if (flags->prec < (int)ft_strlen(nbr_di))
		return (ft_get_result_di(nbr_di, flags));
	i = 0;
	if (nbr_di[i] == '-')
	{
		nbr_di_prec = (char*)malloc(sizeof(char) * flags->prec + 2);
		nbr_di_prec[i++] = '-';
	}
	else
		nbr_di_prec = (char*)malloc(sizeof(char) * flags->prec + 1);
	ft_memset(nbr_di_prec + i, '0', flags->prec);
	nbr_len = nbr < 0 ? ft_strlen(nbr_di) - 1 : ft_strlen(nbr_di);
	ft_strlcpy(nbr_di_prec + i + flags->prec - nbr_len,
									nbr_di + i, nbr_len + 1);
	free(nbr_di);
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
