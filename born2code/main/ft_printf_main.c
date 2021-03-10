#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	// c
	printf("\n========== type c ==========\n");
	printf(", size: %d\n", printf("%c", 'a'));
	printf(", size: %d\n", ft_printf("%c", 'a'));
	printf(", size: %d\n", printf("%010c", 'b'));
	printf(", size: %d\n", ft_printf("%010c", 'b'));
	printf(", size: %d\n", printf("%5c", 'c'));
	printf(", size: %d\n", ft_printf("%5c", 'c'));
	printf(", size: %d\n", printf("%-5c", 'd'));
	printf(", size: %d\n", ft_printf("%-5c", 'd'));
	printf(", size: %d\n", printf("%c", 0));
	printf(", size: %d\n", ft_printf("%c", 0));
	printf(", size: %d\n", printf("%5c", 0));
	printf(", size: %d\n", ft_printf("%5c", 0));
	printf(", size: %d\n", printf("this is [type %c] test", 'c'));
	printf(", size: %d\n", ft_printf("this is [type %c] test", 'c'));


	// s
	printf("\n========== type s ==========\n");
	printf(", size: %d\n", printf("%s", "abcde"));
	printf(", size: %d\n", ft_printf("%s", "abcde"));
	printf(", size: %d\n", printf("%010s", "hello"));
	printf(", size: %d\n", ft_printf("%010s", "hello"));
	printf(", size: %d\n", printf("%-s", "world"));
	printf(", size: %d\n", ft_printf("%-s", "world"));
	printf(", size: %d\n", printf("%10.5s", "norm"));
	printf(", size: %d\n", ft_printf("%10.5s", "norm"));
	printf(", size: %d\n", printf("%-.10s", "hate"));
	printf(", size: %d\n", ft_printf("%-.10s", "hate"));
	printf(", size: %d\n", printf("this is [%s] test", "type s"));
	printf(", size: %d\n", ft_printf("this is [%s] test", "type s"));

	// p
	printf("\n========== type p ==========\n");
	printf(", size: %d\n", printf("%p", 0x101132f47));
	printf(", size: %d\n", ft_printf("%p", 0x101132f47));
	printf(", size: %d\n", printf("%20.5p", 0x101132f47));
	printf(", size: %d\n", ft_printf("%20.5p", 0x101132f47));
	printf(", size: %d\n", printf("%p", 0));
	printf(", size: %d\n", ft_printf("%p", 0));
	printf(", size: %d\n", printf("%5p", 0));
	printf(", size: %d\n", ft_printf("%5p", 0));
	printf(", size: %d\n", printf("this is [type p] test: %p", 0x1234));
	printf(", size: %d\n", ft_printf("this is [type p] test: %p", 0x1234));


	// d
	printf("\n========== type d ==========\n");
	printf(", size: %d\n", printf("%d", 23452));
	printf(", size: %d\n", ft_printf("%d", 23452));
	printf(", size: %d\n", printf("%-10d", 12345));
	printf(", size: %d\n", ft_printf("%-10d", 12345));
	printf(", size: %d\n", printf("%010d", 54321));
	printf(", size: %d\n", ft_printf("%010d", 54321));
	printf(", size: %d\n", printf("%010d", -54321));
	printf(", size: %d\n", ft_printf("%010d", -54321));
	printf(", size: %d\n", printf("%10d", -54321));
	printf(", size: %d\n", ft_printf("%10d", -54321));
	printf(", size: %d\n", printf("%10.3d", 23452));
	printf(", size: %d\n", ft_printf("%10.3d", 23452));
	printf(", size: %d\n", printf("%10.7d", 23452));
	printf(", size: %d\n", ft_printf("%10.7d", 23452));
	printf(", size: %d\n", printf("this is [type d] test: %10.7d", 23452));
	printf(", size: %d\n", ft_printf("this is [type d] test: %10.7d", 23452));


	// i
	printf("\n========== type i ==========\n");
	printf(", size: %d\n", printf("%i", 23452));
	printf(", size: %d\n", ft_printf("%i", 23452));
	printf(", size: %d\n", printf("%-10i", 12345));
	printf(", size: %d\n", ft_printf("%-10i", 12345));
	printf(", size: %d\n", printf("%010i", 54321));
	printf(", size: %d\n", ft_printf("%010i", 54321));
	printf(", size: %d\n", printf("%010i", -23452));
	printf(", size: %d\n", ft_printf("%010i", -23452));
	printf(", size: %d\n", printf("%10i", -23452));
	printf(", size: %d\n", ft_printf("%10i", -23452));
	printf(", size: %d\n", printf("%10.3i", 23452));
	printf(", size: %d\n", ft_printf("%10.3i", 23452));
	printf(", size: %d\n", printf("%10.7i", 23452));
	printf(", size: %d\n", ft_printf("%10.7i", 23452));
	printf(", size: %d\n", printf("this is [type i] test: %10.7i", 23452));
	printf(", size: %d\n", ft_printf("this is [type i] test: %10.7i", 23452));


	// u
	printf("\n========== type u ==========\n");
	printf(", size: %d\n", printf("%u", 23452));
	printf(", size: %d\n", ft_printf("%u", 23452));
	printf(", size: %d\n", printf("%-10u", 12345));
	printf(", size: %d\n", ft_printf("%-10u", 12345));
	printf(", size: %d\n", printf("%010u", 54321));
	printf(", size: %d\n", ft_printf("%010u", 54321));
	printf(", size: %d\n", printf("%10.3u", 23452));
	printf(", size: %d\n", ft_printf("%10.3u", 23452));
	printf(", size: %d\n", printf("%10.7u", 23452));
	printf(", size: %d\n", ft_printf("%10.7u", 23452));
	printf(", size: %d\n", printf("%u", -23452));
	printf(", size: %d\n", ft_printf("%u", -23452));
	printf(", size: %d\n", printf("this is [type i] test: %10.7u", 23452));
	printf(", size: %d\n", ft_printf("this is [type i] test: %10.7u", 23452));


	// x
	printf("\n========== type x ==========\n");
	printf(", size: %d\n", printf("%x", 113801));
	printf(", size: %d\n", ft_printf("%x", 113801));

	// X
	printf("\n========== type X ==========\n");
	printf(", size: %d\n", printf("%X", 113801));
	printf(", size: %d\n", ft_printf("%X", 113801));


	// %
	printf("\n========== type %% ==========\n");
	printf(", size: %d\n", printf("%%"));
	printf(", size: %d\n", ft_printf("%%"));

	printf("\n");
	system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");

	return (0);
}
