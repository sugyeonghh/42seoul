/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:25:47 by shong             #+#    #+#             */
/*   Updated: 2020/12/28 23:24:09 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int		ft_atoi(const char *str)
{
	int			sign;
	int			cnt;
	long long	num;

	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
	|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	num = 0;
	cnt = 0;
	while (*str >= '0' && *str <= '9')
	{
		if ((unsigned long long)num >= LLONG_MAX - 1)
		{
			num = sign > 0 ? -1 : 0;
			return (num);
		}
		num = num * 10 + (*str++ - 48);
		cnt++;
	}
	return ((int)num * sign);
}
