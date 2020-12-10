/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 07:46:06 by shong             #+#    #+#             */
/*   Updated: 2020/12/02 20:31:57 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_len(char *str)
{
	unsigned i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				i;
	unsigned int	j;
	unsigned int	len_dest;
	unsigned int	len_src;

	i = 0;
	j = 0;
	len_dest = ft_len(dest);
	len_src = ft_len(src);
	if (size == 0)
		return (len_src);
	else if (size <= ft_len(dest))
		return (len_src + size);
	else
	{
		if (size - 1 > 0)
		{
			while (dest[i] != 0)
				i++;
			while (src[j] != 0 && j < size - len_dest - 1)
				dest[i++] = src[j++];
			dest[i] = 0;
		}
		return (len_src + len_dest);
	}
}
