/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:13:38 by shong             #+#    #+#             */
/*   Updated: 2020/12/24 16:14:53 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		len;
	int		i;

	len = ft_strlen(s1);
	if (!(tmp = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);	
}