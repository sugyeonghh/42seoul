/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:47:31 by shong             #+#    #+#             */
/*   Updated: 2021/02/16 04:00:22 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flag_init(t_flag *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->width = 0;
	flags->prec = 0;
}

static int	ft_get_width_or_prec(char **format, va_list ap, t_flag *flags)
{
	int		nbr;

	if (**format == '*')
	{
		nbr = va_arg(ap, int);
		if (nbr < 0)
		{
			if (flags->dot)
				return (flags->dot = 0);
			flags->minus = 1;
			nbr *= -1;
		}
	}
	else
	{
		nbr = 0;
		while (ft_isdigit(**format))
		{
			nbr = nbr * 10 + **format - '0';
			(*format)++;
		}
		(*format)--;
	}
	return (nbr);
}

static void	ft_flag_parse(char **format, va_list ap, t_flag *flags)
{
	while (!ft_strchr("cspdiuxX", **format))
	{
		if (**format == '-')
			flags->minus = 1;
		else if (!flags->dot && **format == '0')
			flags->zero = 1;
		else if (**format == '.')
			flags->dot = 1;
		else if (ft_isdigit(**format) || **format == '*')
		{
			if (!(flags->dot))
				flags->width = ft_get_width_or_prec(format, ap, flags);
			else
				flags->prec = ft_get_width_or_prec(format, ap, flags);
		}
		(*format)++;
	}
}

int			ft_print_type(char **format, va_list ap)
{
	t_flag	flags;

	ft_flag_init(&flags);
	ft_flag_parse(format, ap, &flags);
	if (**format == 'c')
		return (ft_type_c(va_arg(ap, int), &flags));
	else if (**format == 'p')
		return (ft_type_p(va_arg(ap, unsigned long long), &flags));
	else if (**format == 's')
		return (ft_type_s(va_arg(ap, char *), &flags));
	else if (ft_strchr("di", **format))
		return (ft_type_di(va_arg(ap, int), &flags));
	else if (ft_strchr("uxX", **format))
		return (ft_type_ux(**format, va_arg(ap, unsigned int), &flags));
	return (0);
}
