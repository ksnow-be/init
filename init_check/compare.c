#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	buff1[1000];
	char	buff2[1000];
	int		fd1, fd2;
	int		rd1, rd2;
	char	*res1;
	char	*res2;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	rd1 = read(fd1, buff1, 1000);
	rd2 = read(fd2, buff2, 1000);
	res1 = (char *)malloc((sizeof(char*) * strlen(buff1)));
	res2 = (char *)malloc((sizeof(char*) * strlen(buff2)));
	
	if (res1)
		res1 = buff1;
	if (res2)
		res2 = buff2;
	if (!(strcmp(res1, res2)))
		printf("\033[32mSAME\033[m\n");
	else
		printf("\033[31mDIFFERENT\033[m\n");
		
	return (0);
}
