/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 04:41:52 by shong             #+#    #+#             */
/*   Updated: 2020/12/07 19:03:35 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;
	int result;

	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	i = 1;
	result = 1;
	while (i <= nb)
		result *= i++;
	return (result);
}
