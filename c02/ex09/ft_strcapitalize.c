/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:49:09 by shong             #+#    #+#             */
/*   Updated: 2020/11/30 22:42:18 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_word(char *str)
{
	int word;

	if (*str >= 'a' && *str <= 'z')
		word = 1;
	else if (*str >= 'A' && *str <= 'Z')
		word = 2;
	else if (*str >= '0' && *str <= '9')
		word = 3;
	else
		word = 0;
	return (word);
}

int		ft_is_cap(char *str, int is_cap, int word)
{
	if (is_cap == 1)
	{
		if (word == 0)
			is_cap = 1;
		else
		{
			if (word == 1)
				*str -= 32;
			is_cap = 0;
		}
	}
	else
	{
		if (word == 2)
			*str += 32;
		else if (word == 0)
			is_cap = 1;
	}
	return (is_cap);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int is_cap;
	int word;

	i = 0;
	is_cap = 1;
	while (str[i] != 0)
	{
		word = ft_is_word(str + i);
		is_cap = ft_is_cap(str + i, is_cap, word);
		i++;
	}
	return (str);
}
