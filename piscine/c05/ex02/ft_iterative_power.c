/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 04:50:43 by shong             #+#    #+#             */
/*   Updated: 2020/12/07 19:19:02 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int result;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	result = 1;
	while (power--)
		result *= nb;
	return (result);
}
