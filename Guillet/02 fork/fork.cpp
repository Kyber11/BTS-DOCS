#include <stdio.h> 
#include <string.h> 
#include <unistd.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
  pid_t child_pid;
  cout << "pid de ce processus : " << getpid () << endl;
  sleep(10);
  child_pid = fork ();
  if (child_pid != 0) {
      // processus père
    cout << "fork à renvoyé le nombre " << child_pid << ", je suis donc le père et ce numéro est le pid du processus fils que je viens de créé." << endl;
    cout << "le mien c'est toujours : " << getpid () << endl;
    while (1)
    {
        printf("*");
        fflush(stdout);
        sleep(1);
    }
  }
  else
  {
      //processus fils
    cout << "fork à renvoyé le nombre 0, je suis le processus qui vient d'être créé." << endl;
    cout << "mon identifiant est : " << getpid () << endl;
    cout << "celui de mon père  est : " << getppid () << endl;
    while (1)
    {
        printf("+");
        fflush(stdout);
        sleep(1);
    }
  }
  return 0;
}
