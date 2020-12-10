/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 10:38:19 by shong             #+#    #+#             */
/*   Updated: 2020/12/09 13:05:57 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int		ft_find_min(int argc, char *argv[], int start)
{
	int min;
	int i;

	min = start;
	i = start + 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], argv[min]) < 0)
			min = i;
		i++;
	}
	return (min);
}

void	ft_sort_params(int argc, char *argv[])
{
	int start;
	int min;

	start = 1;
	while (start < argc - 1)
	{
		min = ft_find_min(argc, argv, start);
		ft_swap(&argv[start], &argv[min]);
		start++;
	}
}

int		main(int argc, char *argv[])
{
	int	i;
	int len;

	i = 1;
	ft_sort_params(argc, argv);
	while (i < argc)
	{
		len = 0;
		while (argv[i][len] != 0)
			len++;
		write(1, argv[i], len);
		write(1, "\n", 1);
		i++;
	}
}
