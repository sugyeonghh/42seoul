/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 03:32:43 by shong             #+#    #+#             */
/*   Updated: 2020/12/25 03:51:11 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_size(int n)
{
	if (n < 10)
		return (1);
	return (1 + ft_size(n / 10));
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		size;

	i = 0;
	if (n < 0)
	{
		res[i++] = '-';
		n *= -1;
	}
	size = ft_size(n);
	
}

int main(void)
{
	printf("%d \n", ft_size(7));
}