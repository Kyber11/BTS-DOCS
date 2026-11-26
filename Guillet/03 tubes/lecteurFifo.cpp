#include <stdio.h>
#include <sys/fcntl.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int fd;
    char buf[50];
    fd = open("tubeFifo", O_RDONLY);
    read(fd, buf, sizeof(buf));
    printf("%s", buf);
    return 0;
}
