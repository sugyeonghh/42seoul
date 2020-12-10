/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:03:43 by shong             #+#    #+#             */
/*   Updated: 2020/11/25 15:07:11 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_min(int *tab, int size, int start)
{
	int min;
	int i;

	min = start;
	i = start + 1;
	while (i < size)
	{
		if (tab[i] < tab[min])
			min = i;
		i++;
	}
	return (min);
}

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int start;
	int min;

	start = 0;
	while (start < size - 1)
	{
		min = ft_find_min(tab, size, start);
		ft_swap(&tab[start], &tab[min]);
		start++;
	}
}
