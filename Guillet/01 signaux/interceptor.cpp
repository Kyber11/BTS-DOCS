#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main ()
{
  pid_t pid = getpid();
  printf("mon pid : %d\n", (int) pid);
  while (1)
  {
      printf("*");
      fflush(stdout);
      sleep(1);
  }
}
