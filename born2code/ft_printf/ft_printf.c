/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:20:40 by shong             #+#    #+#             */
/*   Updated: 2021/02/06 23:00:13 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_init(t_flag *flags)
{
	flags->star = 0;
	flags->dot = 0;
	flags->width = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->pre = 0;
}

int		ft_treatment(int c, t_flag *flags, va_list ap)
{
	if (c == 'c')
		return (ft_type_c(flags, ap));
	else if (c == 'p')
		return (ft_type_p(flags, ap));

	return (0);
}

int		ft_flag_parse(const char *save, int i, t_flag *flags)
{
	while (save[i])
	{
		if (!ft_isdigit(save[i]) && !ft_strchr("-0.*", save[i]) && 
											!ft_strchr("cspdiuxX%",save[i]))
			break ;
		if (save[i] == '0')
			flags->zero = 1;
		else if (save[i] == '.')
			flags->dot = 1;
		else if (save[i] == '-')
			flags->minus = 1;
		else if (save[i] == '*')
			flags->star = 1;
		else if (ft_isdigit(save[i]))
		{
			if (!(flags->dot))
				flags->width = (flags->width) * 10 + save[i];
			else
				flags->pre = (flags->pre) * 10 + save[i];
		}
		else if (ft_strchr("cspdiuxX", save[i]))
			return (i);
		i++;
	}
	return (i);
}

int		ft_treat_save(const char *save, va_list ap)
{
	int		i;
	int		return_value;
	t_flag	flag_info;

	i = 0;
	return_value = 0;
	while (save[i])
	{
		flag_init(&flag_info);
		if (save[i] == '%' && save[i + 1] != 0)
		{
			i = ft_flag_parse(save, i, &flag_info);
			if (ft_strchr("cspdiuxX%", save[i]))
				return_value += ft_treatment(save[i], &flag_info, ap);
			else if (save[i])
			{
				return_value += 1;
				ft_putchar_fd(save[i], 1);
			}
		}
		else if (save[i] != '%')
		{
			return_value += 1;
			ft_putchar_fd(save[i], 1);
		}
		i++;
	}
	return (return_value);
}

int		ft_printf(const char *format, ...)
{
	const char	*save;
	va_list		ap;
	int			return_value;

	return_value = 0;
	save = ft_strdup(format);
	va_start(ap, format);
	return_value += ft_treat_save(save, ap);
	va_end(ap);
	free((char*)save);
	return (return_value);
}

int main(void)
{
	int a = 10;
	ft_printf("c: %5c\n", 'a');
	printf("c: %5c\n", 'a');
	// ft_printf("p: %p\n", &a);
	// printf("p: %p\n", &a);
	// ft_printf("%%: %%\n");
	// printf("%%: %%\n");

}
