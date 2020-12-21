/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:33:09 by shong             #+#    #+#             */
/*   Updated: 2020/11/22 12:47:07 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_puterror(void);

char	g_arr[6] = {'/', '\\', '\\', '/', '*', '*'};

void	ft_print_column(char start, char mid, char end, int x)
{
	int x_pos;

	x_pos = 1;
	while (x_pos <= x)
	{
		if (x_pos == 1)
		{
			ft_putchar(start);
		}
		else if (x_pos < x)
		{
			ft_putchar(mid);
		}
		else
		{
			ft_putchar(end);
		}
		x_pos++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int y_pos;

	y_pos = 1;
	if (x <= 0 || y <= 0)
	{
		ft_puterror();
		return ;
	}
	while (y_pos <= y)
	{
		if (y_pos == 1)
		{
			ft_print_column(g_arr[0], g_arr[4], g_arr[1], x);
		}
		else if (y_pos < y)
		{
			ft_print_column(g_arr[5], ' ', g_arr[5], x);
		}
		else
		{
			ft_print_column(g_arr[2], g_arr[4], g_arr[3], x);
		}
		y_pos++;
	}
}
