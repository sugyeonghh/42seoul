/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 03:32:43 by shong             #+#    #+#             */
/*   Updated: 2020/12/26 22:07:53 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size(long long ln)
{
	if (ln < 10)
		return (1);
	return (1 + ft_size(ln / 10));
}

char	*ft_itoa(int n)
{
	char		*res;
	int			size;
	int			sign;
	long long	ln;

	ln = n;
	size = (ln >= 0) ? ft_size(ln) : ft_size(-ln) + 1;
	if (!(res = malloc(size + 1)))
		return (0);
	sign = 0;
	res[size--] = 0;
	if (ln < 0)
	{
		sign = 1;
		res[0] = '-';
		ln *= -1;
	}
	while (size >= (sign ? 1 : 0))
	{
		res[size--] = ln % 10 + '0';
		ln = ln / 10;
	}
	return (res);
}
