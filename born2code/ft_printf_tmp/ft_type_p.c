/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:50:12 by shong             #+#    #+#             */
/*   Updated: 2021/02/06 22:59:15 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_invalid(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	i = 0;
	while (base[i] != 0)
	{
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_set_result(char *base, unsigned long long nbr, int res_len)
{
	int		res[res_len];
	char	result[res_len];
	int		i;
	int		b;
	int		size;

	b = ft_strlen(base);
	size = res_len;
	while (size)
	{
		res[size - 1] = nbr % b;
		nbr /= b;
		size--;
	}
	i = 0;
	while (i < res_len)
	{
		result[i] = base[res[i]];
		i++;
	}
	write(1, result, res_len);
}

void	ft_putnbr_base_ull(unsigned long long nbr, char *base)
{
	unsigned long long	tmp;
	int 				res_len;

	if (ft_strlen(base) <= 1 || ft_invalid(base) == 1)
		return ;
	tmp = nbr;
	res_len = 0;
	while (tmp)
	{
		res_len++;
		tmp /= ft_strlen(base);
	}
	tmp = nbr;
	ft_set_result(base, tmp, res_len);
}

int		ft_type_p(t_flag *flags, va_list ap)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_ull(va_arg(ap, unsigned long long), "0123456789abcdef");
	return (0);
}
