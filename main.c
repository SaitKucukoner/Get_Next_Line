#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd = open("file.txt" , O_RDONLY);
	char *c;
	
	while ((c = get_next_line(fd)))
		printf("%s", c);
}