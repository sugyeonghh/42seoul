/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:22:03 by shong             #+#    #+#             */
/*   Updated: 2020/11/30 22:42:06 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_hex(unsigned char hex)
{
	char c;

	if (hex <= 9)
		c = '0' + hex;
	else
		c = 'a' + hex - 10;
	write(1, &c, 1);
}

void	ft_into_hex(unsigned char hex)
{
	ft_put_hex(hex / 16);
	ft_put_hex(hex % 16);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, str + i, 1);
		else
		{
			write(1, "\\", 1);
			ft_into_hex(str[i]);
		}
		i++;
	}
}
