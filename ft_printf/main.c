#include <stdio.h>
#include "ft_printf.h"

int main (void)
{
//	char *line = "sd,sfdfdf";
  //char c = 'a';
    //char *p;
   //e p = &c;
/*	int fd;
	int i = 0;

	fd = open("text1.txt", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("(%s)\n\n%d\n", line, i);
		free(line);
	}
	printf("(%s)\n\n%d\n", line, i);
	free(line);*/

//	printf("%*.*X",-20, 5,-255);
//	printf("%000*.*d|\n", 9, -1, -12);
//	ft_printf("%000*.*d|\n", 9, -1, -12);
	//printf("%00*.*d|\n",4,-2, -12);
//	printf("%000*d|\n", 5, 42);
//	ft_printf("%000*d", 5, 42);
	printf("%*s",5, -6, 7, "42");
}
