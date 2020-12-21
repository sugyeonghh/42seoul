/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 02:56:04 by sook-yeon         #+#    #+#             */
/*   Updated: 2020/12/09 12:22:37 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int a;

	if (nb <= 1)
		return (0);
	else if (nb == 2)
		return (1);
	a = 3;
	while (a <= nb / a || nb % 2 == 0)
	{
		if (nb % a == 0)
			return (0);
		a++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int n;

	if (ft_is_prime(nb) == 1)
		return (nb);
	n = nb;
	while (1)
	{
		if (ft_is_prime(n) == 1)
			return (n);
		n++;
	}
}
