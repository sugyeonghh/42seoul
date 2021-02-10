
#include "ft_printf.h"

int		main(void)
{
	// c
	printf("========== type c ==========\n");
	printf(", size: %d\n", printf("hello %c world!",'a'));
	printf(", size: %d\n", ft_printf("hello %c world!",'a'));
	printf(", size: %d\n", printf("%-*c", 5, 'a'));
	printf(", size: %d\n", ft_printf("%-*c", 5, 'a'));
	printf(", size: %d\n", printf("%*c", 0, 'a'));
	printf(", size: %d\n", ft_printf("%*c", 0, 'a'));
	printf(", size: %d\n", printf("%010c", 'a'));
	printf(", size: %d\n", ft_printf("%010c", 'a'));
	printf(", size: %d\n", printf("%-2c", 'b'));
	printf(", size: %d\n", ft_printf("%-2c", 'b'));
	printf(", size: %d\n", printf("%-c", '0'));
	printf(", size: %d\n", ft_printf("%-c", '0'));

	
/*	// s
	printf("========== type s ==========\n");
	printf(", size: %d\n", printf("%s", "abcde"));
	printf(", size: %d\n", ft_printf("%s", "abcde"));
	printf(", size: %d\n", printf("%10s", "abcde"));
	printf(", size: %d\n", ft_printf("%10s", "abcde"));
	printf(", size: %d\n", printf("%-10s", "abcde"));
	printf(", size: %d\n", ft_printf("%-10s", "abcde"));
	printf(", size: %d\n", printf("%*s", 10, "abcde"));
	printf(", size: %d\n", ft_printf("%*s", 10, "abcde"));
	printf(", size: %d\n", printf("%*.3s", 10, "abcde"));
	printf(", size: %d\n", ft_printf("%*.3s", 10, "abcde"));
	printf(", size: %d\n", printf("%*.5s", 10, "abcde"));
	printf(", size: %d\n", ft_printf("%*.5s", 10, "abcde"));
	printf(", size: %d\n", printf("%-*s", 10, "0"));
	printf(", size: %d\n", ft_printf("%-*s", 10, "0"));


	// p
	printf("========== type p ==========\n");
	printf(", size: %d\n", printf("%p", 0x101132f47));
	printf(", size: %d\n", ft_printf("%p", 0x101132f47));
	printf(", size: %d\n", printf("%10p", 0x101132f47));
	printf(", size: %d\n", ft_printf("%10p", 0x101132f47));
	printf(", size: %d\n", printf("%-20p", 0x101132f47));
	printf(", size: %d\n", ft_printf("%-20p", 0x101132f47));
	printf(", size: %d\n", printf("%20p", 0x101132f47));
	printf(", size: %d\n", ft_printf("%20p", 0x101132f47));
	
	
	// d
	printf("========== type d ==========\n");
	printf(", size: %d\n", printf("%d", 23452));
	printf(", size: %d\n", ft_printf("%d", 23452));
	printf(", size: %d\n", printf("%10d", 23452));
	printf(", size: %d\n", ft_printf("%*d", 10, 23452));
	printf(", size: %d\n", printf("%10.3d", 23452));
	printf(", size: %d\n", ft_printf("%10.3d", 23452));
	printf(", size: %d\n", printf("%10.6d", 23452));
	printf(", size: %d\n", ft_printf("%10.6d", 23452));
	printf(", size: %d\n", printf("%-10d", 23452));
	printf(", size: %d\n", ft_printf("%-10d", 23452));
	printf(", size: %d\n", printf("%010d", 23452));
	printf(", size: %d\n", ft_printf("%010d", 23452));
	printf(", size: %d\n", printf("%-010d", 23452));
	printf(", size: %d\n", ft_printf("%-010d", 23452));




	// i
	printf("========== type i ==========\n");
	printf(", size: %d\n", printf("%i", 23452));
	printf(", size: %d\n", ft_printf("%i", 23452));

	// u
	printf("========== type u ==========\n");
	printf(", size: %d\n", printf("%u", 23452));
	printf(", size: %d\n", ft_printf("%u", 23452));
	printf(", size: %d\n", printf("%10.6u", 23452));
	printf(", size: %d\n", ft_printf("%10.6u", 23452));
	printf(", size: %d\n", printf("%6.8u", 23452));
	printf(", size: %d\n", ft_printf("%6.8u", 23452));
	printf(", size: %d\n", printf("%10.4u", 23452));
	printf(", size: %d\n", ft_printf("%10.4u", 23452));
	printf(", size: %d\n", printf("%4.6u", 23452));
	printf(", size: %d\n", ft_printf("%4.6u", 23452));
	printf(", size: %d\n", printf("%4.3u", 23452));
	printf(", size: %d\n", ft_printf("%4.3u", 23452));
	printf(", size: %d\n", printf("%3.4u", 23452));
	printf(", size: %d\n", ft_printf("%3.4u", 23452));
	printf(", size: %d\n", printf("%-10.6u", 23452));
	printf(", size: %d\n", ft_printf("%-10.6u", 23452));


	// x
	printf("========== type x ==========\n");
	printf(", size: %d\n", printf("%x", 113801));
	printf(", size: %d\n", ft_printf("%x", 113801));
	printf(", size: %d\n", printf("%10.6x", 113801));
	printf(", size: %d\n", ft_printf("%10.6x", 113801));
	printf(", size: %d\n", printf("%6.8x", 113801));
	printf(", size: %d\n", ft_printf("%6.8x", 113801));
	printf(", size: %d\n", printf("%10.4x", 113801));
	printf(", size: %d\n", ft_printf("%10.4x", 113801));
	printf(", size: %d\n", printf("%4.6x", 113801));
	printf(", size: %d\n", ft_printf("%4.6x", 113801));
	printf(", size: %d\n", printf("%4.3x", 113801));
	printf(", size: %d\n", ft_printf("%4.3x", 113801));
	printf(", size: %d\n", printf("%3.4x", 113801));
	printf(", size: %d\n", ft_printf("%3.4x", 113801));
	printf(", size: %d\n", printf("%-10.6x", 113801));
	printf(", size: %d\n", ft_printf("%-10.6x", 113801));


	// X
	printf("========== type X ==========\n");
	printf(", size: %d\n", printf("%X", 113801));
	printf(", size: %d\n", ft_printf("%X", 113801));
	printf(", size: %d\n", printf("%10.6X", 113801));
	printf(", size: %d\n", ft_printf("%10.6X", 113801));
	printf(", size: %d\n", printf("%6.8X", 113801));
	printf(", size: %d\n", ft_printf("%6.8X", 113801));
	printf(", size: %d\n", printf("%10.4X", 113801));
	printf(", size: %d\n", ft_printf("%10.4X", 113801));
	printf(", size: %d\n", printf("%4.6X", 113801));
	printf(", size: %d\n", ft_printf("%4.6X", 113801));
	printf(", size: %d\n", printf("%4.3X", 113801));
	printf(", size: %d\n", ft_printf("%4.3X", 113801));
	printf(", size: %d\n", printf("%3.4X", 113801));
	printf(", size: %d\n", ft_printf("%3.4X", 113801));
	printf(", size: %d\n", printf("%-10.6X", 113801));
	printf(", size: %d\n", ft_printf("%-10.6X", 113801));



	// %
	printf("========== type %% ==========\n");
	printf(", size: %d\n", printf("%%"));
	printf(", size: %d\n", ft_printf("%%"));
*/	
	return (0);
}
