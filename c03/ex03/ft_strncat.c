/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 06:35:58 by shong             #+#    #+#             */
/*   Updated: 2020/12/01 06:42:22 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (nb > 0)
	{
		while (dest[i] != 0)
			i++;
		while (src[j] != 0 && j != nb)
			dest[i++] = src[j++];
		dest[i] = 0;
	}
	return (dest);
}
