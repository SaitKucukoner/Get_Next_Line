#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd = open("try.txt", O_RDONLY);
    char *c;

    while ((c = get_next_line(fd)))
        printf("%s",c);
    free(c);
}