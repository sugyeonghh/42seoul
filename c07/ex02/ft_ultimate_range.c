/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:06:13 by shong             #+#    #+#             */
/*   Updated: 2020/12/09 18:09:45 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *result;
	int i;
	int size;

	if (min >= max)
	{
		result = NULL;
		return (0);
	}
	size = max - min;
	if (!(result = (int *)malloc(sizeof(int) * size)))
		return (-1);
	i = 0;
	while (i < size)
		result[i++] = min++;
	*range = result;
	return (size);
}
