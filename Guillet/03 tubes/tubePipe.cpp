#include <stdio.h>
#include <sys/fcntl.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int fd;
    char buf[50];
    fd = open("tubeFifo", O_WRONLY);
    write(fd, "coucou", 6);
    printf("message envoyé\n");
    close(fd);
    return 0;
}
