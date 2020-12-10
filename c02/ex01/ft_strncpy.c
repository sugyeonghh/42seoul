/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 03:15:59 by shong             #+#    #+#             */
/*   Updated: 2020/12/03 23:34:34 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	if (n != 0)
	{
		i = 0;
		while (i < n)
		{
			if (src[i] == 0)
				while (i < n)
					dest[i++] = 0;
			else
				dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}
