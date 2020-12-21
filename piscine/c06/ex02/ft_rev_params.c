/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 10:38:11 by shong             #+#    #+#             */
/*   Updated: 2020/12/09 10:42:39 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

int	main(int argc, char *argv[])
{
	int i;

	i = argc;
	while (i > 1)
	{
		write(1, argv[i - 1], ft_len(argv[i - 1]));
		write(1, "\n", 1);
		i--;
	}
}
