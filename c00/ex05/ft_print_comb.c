/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:27:58 by shong             #+#    #+#             */
/*   Updated: 2020/12/01 00:27:45 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_three(char c1, char c2, char c3)
{
	write(1, &c1, 1);
	write(1, &c2, 1);
	write(1, &c3, 1);
}

void	ft_print_comb(void)
{
	int num[3];

	num[0] = 0;
	while (num[0] <= 7)
	{
		num[1] = num[0] + 1;
		while (num[1] <= 8)
		{
			num[2] = num[1] + 1;
			while (num[2] <= 9)
			{
				if (num[0] == 7 && num[1] == 8 && num[2] == 9)
				{
					ft_putchar_three('7', '8', '9');
					break ;
				}
				ft_putchar_three(num[0] + 48, num[1] + 48, num[2] + 48);
				ft_putchar(',');
				ft_putchar(' ');
				num[2] += 1;
			}
			num[1] += 1;
		}
		num[0] += 1;
	}
}
