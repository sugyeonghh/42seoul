/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_uxX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 06:29:05 by shong             #+#    #+#             */
/*   Updated: 2021/02/16 01:23:52 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_uitoa_base(unsigned int nbr, const char *base)
{
	unsigned int	tmp;
	int				nbr_len;
	char			*nbr_uxX;
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

	if (!flags->width || flags->width <= (int)ft_strlen(nbr_uxX))
		return (nbr_uxX);
	// %u, 0
	if (flags->zero && !flags->dot && !flags->minus && !flags->prec && ft_strlen(nbr_uxX))
		expand = ft_str_filled_with('0', flags->width - (int)ft_strlen(nbr_uxX));
	else
		expand = ft_str_filled_with(' ', flags->width - (int)ft_strlen(nbr_uxX));
	if (flags->minus)
		res = ft_strjoin(nbr_uxX, expand);
	else if (*expand == ' ')
		res = ft_strjoin(expand, nbr_uxX);
	else
	{
		res = (char *)malloc(sizeof(char) * flags->width + 1);
		ft_memset(res, '0', flags->width);
		ft_strlcpy(res + flags->width - ft_strlen(nbr_uxX), nbr_uxX, ft_strlen(nbr_uxX) + 1);
	}
	free(nbr_uxX);
	free(expand);
	return (res);
}

static char	*ft_get_nbr_uxX(const char format, unsigned int nbr, t_flag *flags)
{
	char	*nbr_uxX;
	char	*nbr_uxX_prec;
	char	*base;
	int		i;
	
	if (format == 'u')
		base = "0123456789";
	else if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (flags->dot && !flags->prec && !nbr)
		return (ft_get_result_uxX(ft_strdup(""), flags));
	nbr_uxX = ft_uitoa_base(nbr, base);
	if (flags->prec < (int)ft_strlen(nbr_uxX))
		return (ft_get_result_uxX(nbr_uxX, flags));
	i = 0;
	if (nbr_uxX[i] == '-')
	{
		nbr_uxX_prec = (char*)malloc(sizeof(char) * flags->prec + 2);
		nbr_uxX_prec[i++] = '-';
	}
	else
		nbr_uxX_prec = (char*)malloc(sizeof(char) * flags->prec + 1);
	ft_memset(nbr_uxX_prec + i, '0', flags->prec);
	ft_strlcpy(nbr_uxX_prec + i + flags->prec - ft_strlen(nbr_uxX), nbr_uxX + i, ft_strlen(nbr_uxX) + 1);
	free(nbr_uxX);
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
