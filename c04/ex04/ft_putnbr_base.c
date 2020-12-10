/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 00:08:37 by shong             #+#    #+#             */
/*   Updated: 2020/12/07 17:22:45 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

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

void	ft_set_result(char *base, int nbr, int sign, int res_len)
{
	int		res[res_len];
	char	result[res_len];
	int		i;
	int		b;
	int		size;

	b = ft_len(base);
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
	if (sign == -1)
		write(1, "-", 1);
	write(1, result, res_len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int tmp;
	int sign;
	int res_len;

	if (ft_len(base) <= 1 || ft_invalid(base) == 1)
		return ;
	sign = nbr > 0 ? 1 : -1;
	tmp = nbr > 0 ? nbr : -nbr;
	res_len = 0;
	while (tmp)
	{
		res_len++;
		tmp /= ft_len(base);
	}
	tmp = nbr > 0 ? nbr : -nbr;
	ft_set_result(base, tmp, sign, res_len);
}
