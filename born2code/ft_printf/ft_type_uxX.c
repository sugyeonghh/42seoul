/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_uxX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 06:29:05 by shong             #+#    #+#             */
/*   Updated: 2021/02/15 00:21:33 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_uitoa_base(unsigned int nbr, const char *base)
{
	unsigned int	tmp;
	int				nbr_len;
	char			*nbr_uxX;
	int				base_len;

	tmp = nbr;
	nbr_len = 0;
	base_len = (int)ft_strlen(base);
	while (tmp)
	{
		nbr_len++;
		tmp /= base_len;
	}
	nbr_uxX = (char *)malloc(sizeof(char) * nbr_len + 1);
	nbr_uxX[nbr_len] = 0;
	while (nbr_len--)
	{
		nbr_uxX[nbr_len] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (nbr_uxX);
}

static char	*ft_get_result_uxX(char *nbr_uxX, t_flag *flags)
{
	char	*res;
	char	*expand;

	if (flags->width <= (int)ft_strlen(nbr_uxX))
		return (nbr_uxX);

	if (flags->zero && !flags->minus)
		expand = ft_str_filled_with('0', flags->width - (int)ft_strlen(nbr_uxX));
	else
		expand = ft_str_filled_with(' ', flags->width - (int)ft_strlen(nbr_uxX));
	if (flags->minus)
		res = ft_strjoin(nbr_uxX, expand);
	else
		res = ft_strjoin(expand, nbr_uxX);
	free(nbr_uxX);
	free(expand);
	return (res);
}

static char	*ft_get_nbr_uxX(const char format, unsigned int nbr, t_flag *flags)
{
	char	*nbr_uxX;
	char	*zero;
	char	*nbr_uxX_prec;
	char	*base;
	
	if (format == 'u')
		base = "0123456789";
	else if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (flags->dot && !flags->prec && !nbr)
		return (ft_get_result_uxX(ft_strdup(""), flags));
	nbr_uxX = ft_uitoa_base(nbr, base);
	if (flags->prec <= (int)ft_strlen(nbr_uxX))
		return (ft_get_result_uxX(nbr_uxX, flags));
	zero = ft_str_filled_with('0', flags->prec - (int)ft_strlen(nbr_uxX));
	nbr_uxX_prec = ft_strjoin(zero, nbr_uxX);
	free(nbr_uxX);
	free(zero);
	return (ft_get_result_uxX(nbr_uxX_prec, flags));
}

int			ft_type_uxX(const char format, unsigned int nbr, t_flag *flags)
{
	char	*res;
	int		res_size;

	res = ft_get_nbr_uxX(format, nbr, flags);
	res_size = ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (res_size);
}
