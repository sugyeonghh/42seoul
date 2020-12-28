/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:57:59 by shong             #+#    #+#             */
/*   Updated: 2020/12/28 16:22:41 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_word_count(char const *s, char c)
{
	int		cnt;

	cnt = 0;
	while (*s)
	{
		if (*s++ == c)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_size;
	int		i;

	if (!s || !c || !(res = malloc(sizeof(char *) * (ft_word_count(s, c) + 1))))
		return (0);
	i = 0;
	while (*s)
	{
		word_size = 0;
		while (*s != c)
		{
			word_size++;
			s++;
		}
		if (!(res[i] = (char *)malloc((word_size + 1))))
		{
			i = 0;
			while (res[i])
				free(res[i++]);
			free(res);
			return (0);
		}
		ft_strlcpy(res[i++], s - word_size, word_size + 1);
		while (*s == c)
			s++;
	}
	res[i] = 0;
	return (res);
}
#include <stdio.h>
int main(void)
{
	char	**res;
	
	res = ft_split("a,,,ab,abc", ',');
	while (*res)
		printf("%s \n", *res++);

}