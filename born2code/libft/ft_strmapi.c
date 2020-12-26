/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:11:28 by shong             #+#    #+#             */
/*   Updated: 2020/12/26 22:28:58 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s || !f)
		return (0);
	if (!(res = malloc(ft_strlen(s) + 1)))
		return (0);
	i = -1;
	while (++i < ft_strlen(s))
		res[i] = f(i, s[i]);
	res[i] = 0;
	return (res);
}
