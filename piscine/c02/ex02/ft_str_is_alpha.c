/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 03:49:45 by shong             #+#    #+#             */
/*   Updated: 2020/11/30 22:42:14 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_alpha(char *str, int i)
{
	if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
		return (0);
	return (1);
}

int	ft_str_is_alpha(char *str)
{
	int i;
	int is_alp;

	i = 0;
	is_alp = 0;
	while (str[i] != '\0')
	{
		is_alp = ft_is_alpha(str, i++);
		if (is_alp == 0)
			return (is_alp);
	}
	if (i == 0)
		is_alp = 1;
	return (is_alp);
}
