/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:17:16 by shong             #+#    #+#             */
/*   Updated: 2021/02/09 15:33:12 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_init(t_flag *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->star = 0;
	flags->width = 0;
	flags->prec = 0;
}

int		ft_print_type(char format, va_list ap)
{
	t_flag	flags;

	if (format == 'c')
		return (ft_type_c(ap, &flags));
	else if (format == 's')
		return (ft_type_s(ap, &flags));
	else if (format == 'p')
		return (ft_type_p(ap, &flags));
	else if (ft_strchr("diuxX", format))
		return (ft_type_num(ap, &flags));
	else if (format == '%')
		return (ft_type_mod(ap, &flags));
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		size;

	size = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			size += ft_print_type(*++format, ap);
		else
		{
			ft_putchar_fd(*format, 1);
			size++;
		}
		format++;
	}
	va_end(ap);
	return (size);
}

int		main(void)
{
	// c
	printf("========== type c ==========\n");
	printf(", size: %d\n", printf("%c",'a'));
	printf(", size: %d\n", ft_printf("%c",'a'));
	
	// s
	printf("========== type s ==========\n");
	printf(", size: %d\n", printf("%s", "abcde"));
	printf(", size: %d\n", ft_printf("%s", "abcde"));

	// p
	printf("========== type p ==========\n");
	printf(", size: %d\n", printf("%p", 0x101132f47));
	printf(", size: %d\n", ft_printf("%p", 0x101132f47));
	
//	printf(", size; %d\n", printf("today is %-10.3dth.", 6));
/*	// d
	printf("========== type d ==========\n");
	printf(", size: %d\n", printf("%d", 23452));
	printf(", size: %d\n", ft_printf("%d", 23452));

	// i
	printf("========== type i ==========\n");
	printf(", size: %d\n", printf("%i", 23452));
	printf(", size: %d\n", ft_printf("%i", 23452));

	// u
	printf("========== type u ==========\n");
	printf(", size: %d\n", printf("%u", 23452));
	printf(", size: %d\n", ft_printf("%u", 23452));
*/
	// x
	printf("========== type x ==========\n");
	printf(", size: %d\n", printf("%x", 113801));
//	printf(", size: %d\n", ft_printf("%x", 113801));
/*	
	// X
	printf("========== type X ==========\n");
	printf(", size: %d\n", printf("%X", 113801));
	printf(", size: %d\n", ft_printf("%X", 113801));

*/
	// %
	printf("========== type %% ==========\n");
	printf(", size: %d\n", printf("%%"));
	printf(", size: %d\n", ft_printf("%%"));

	
	return (0);
}
