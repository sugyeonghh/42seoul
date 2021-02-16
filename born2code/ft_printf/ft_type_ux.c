/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_ux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 03:59:48 by shong             #+#    #+#             */
/*   Updated: 2021/02/16 23:20:38 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_uitoa_base(unsigned int nbr, const char *base)
{
	unsigned int	tmp;
	int				nbr_len;
	char			*nbr_ux;
	int				base_len;

	if (!nbr)
		return (ft_strdup("0"));
	tmp = nbr;
	nbr_len = 0;
	base_len = (int)ft_strlen(base);
	while (tmp)
	{
		nbr_len++;
		tmp /= base_len;
	}
	nbr_ux = (char *)malloc(sizeof(char) * nbr_len + 1);
	nbr_ux[nbr_len] = 0;
	while (nbr_len--)
	{
		nbr_ux[nbr_len] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (nbr_ux);
}

static char	*ft_get_result_ux(char *nbr_ux, t_flag *flags)
{
	char	*res;
	char	*expand;

	if (!flags->width || flags->width <= (int)ft_strlen(nbr_ux))
		return (nbr_ux);
	if (flags->zero && !flags->dot && !flags->minus &&
										!flags->prec && ft_strlen(nbr_ux))
		expand = ft_str_filled_with('0', flags->width - (int)ft_strlen(nbr_ux));
	else
		expand = ft_str_filled_with(' ', flags->width - (int)ft_strlen(nbr_ux));
	if (flags->minus)
		res = ft_strjoin(nbr_ux, expand);
	else if (*expand == ' ')
		res = ft_strjoin(expand, nbr_ux);
	else
	{
		res = (char *)malloc(sizeof(char) * flags->width + 1);
		ft_memset(res, '0', flags->width);
		ft_strlcpy(res + flags->width - ft_strlen(nbr_ux), nbr_ux,
														ft_strlen(nbr_ux) + 1);
	}
	free(nbr_ux);
	free(expand);
	return (res);
}

static char	*ft_get_nbr_ux(const char format, unsigned int nbr, t_flag *flags)
{
	char	*nbr_ux;
	char	*nbr_ux_prec;
	char	*base;

	if (format == 'u')
		base = "0123456789";
	else if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (flags->dot && !flags->prec && !nbr)
		return (ft_get_result_ux(ft_strdup(""), flags));
	nbr_ux = ft_uitoa_base(nbr, base);
	if (flags->prec < (int)ft_strlen(nbr_ux))
		return (ft_get_result_ux(nbr_ux, flags));
	nbr_ux_prec = (char*)malloc(sizeof(char) * flags->prec + 1);
	ft_memset(nbr_ux_prec, '0', flags->prec);
	ft_strlcpy(nbr_ux_prec + flags->prec - ft_strlen(nbr_ux), nbr_ux,
														ft_strlen(nbr_ux) + 1);
	free(nbr_ux);
	return (ft_get_result_ux(nbr_ux_prec, flags));
}

int			ft_type_ux(const char format, unsigned int nbr, t_flag *flags)
{
	char	*res;
	int		res_size;

	res = ft_get_nbr_ux(format, nbr, flags);
	res_size = ft_strlen(res);
	write(1, res, res_size);
	free(res);
	return (res_size);
}
