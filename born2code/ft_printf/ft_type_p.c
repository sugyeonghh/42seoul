/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:50:12 by shong             #+#    #+#             */
/*   Updated: 2021/02/16 01:31:28 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_result_p(char *address, t_flag *flags)
{
	char	*res;
	char	*space;

	if (flags->width <= (int)ft_strlen(address))
		return (address);
	space = ft_str_filled_with(' ', flags->width - (int)ft_strlen(address));
	if (flags->minus)
		res = ft_strjoin(address, space);
	else
		res = ft_strjoin(space, address);
	free(address);
	free(space);
	return (res);
}

static char	*ft_get_address(unsigned long long nbr, t_flag *flags)
{
	unsigned long long	tmp;
	int 				nbr_len;
	char				*base;
	char				*address;

	if (!nbr)
		return (ft_get_result_p(ft_strdup("0x0"), flags));
	base = "0123456789abcdef";
	tmp = nbr;
	nbr_len = 0;
	while (tmp)
	{
		nbr_len++;
		tmp /= 16;
	}
	address = (char *)malloc(sizeof(char) * nbr_len + 3);
	address[0] = '0';
	address[1] = 'x';
	address[nbr_len + 2] = 0;
	while (nbr_len--)
	{
		address[nbr_len + 2] = base[nbr % 16];
		nbr /= 16;
	}
	return (ft_get_result_p(address, flags));
}

int			ft_type_p(unsigned long long nbr, t_flag *flags)
{
	char	*res;
	int		res_size;

	res = ft_get_address(nbr, flags);
	res_size = ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (res_size);
}
