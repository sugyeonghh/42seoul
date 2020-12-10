#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "find_square.h"

int		main(int argc, char *argv[])
{
	int		fd;
	char 	buf[1000];
	int		i;
	int		num;

	if (argc == 1)
	{
		printf("argv is NULL \n");
		return (0);
	}
	num = 1;
	while (num < argc)
	{
		fd = open(argv[num], O_RDONLY);
		if (fd == -1)
			return (1);
		if (read(fd, buf, sizeof(buf)) == -1)
			return (1);
		printf("%s \n", buf);
		i = 0;
		while (buf[i] != '\n')
			i++;
		// into function
		ft_find
		num++;
	}

}