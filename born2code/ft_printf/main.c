#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
/*	printf("========== type c ==========\n");
	printf(", size: %d\n", printf("%05c", 'a'));
	printf(", size: %d\n", ft_printf("%05c", 'a'));
	
	printf("========== type s ==========\n");
	printf(", size: %d\n", printf("%010s","abcde"));
	printf(", size: %d\n", ft_printf("%010s","abcde"));
	
	printf("========== type p ==========\n");
	int a = 10;
	printf(", size: %d\n", printf("%p", &a));
	printf(", size: %d\n", ft_printf("%p", &a));
	
	printf("========== type d ==========\n");
	printf(", size: %d\n", printf("%d", 23452));
	printf(", size: %d\n", ft_printf("%d", 23452));
	
	printf("========== type i ==========\n");
	printf(", size: %d\n", printf("%010.i", 8));
	printf(", size: %d\n", ft_printf("%010.i",8));
	
	printf("========== type u ==========\n");
	printf(", size: %d\n", printf("%u", 23452));
	printf(", size: %d\n", ft_printf("%u", 23452));
	
	printf("========== type x ==========\n");
	printf(", size: %d\n", printf("%x", 23452));
	printf(", size: %d\n", ft_printf("%x", 23452));
	
	printf("========== type X ==========\n");
	printf(", size: %d\n", printf("%X", 23452));
	printf(", size: %d\n", ft_printf("%X", 23452));
*/
	printf("========== type %% ==========\n");
	printf(", size: %d\n", printf("%02.2%"));
	printf(", size: %d\n", ft_printf("%02.2%"));
	

	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
