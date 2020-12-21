/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:05:55 by shong             #+#    #+#             */
/*   Updated: 2020/12/09 11:06:08 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *result;
	int i;
	int size;

	if (min >= max)
	{
		result = NULL;
		return (result);
	}
	size = max - min;
	if (!(result = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	i = 0;
	while (i < size)
		result[i++] = min++;
	return (result);
}
