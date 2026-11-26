#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
/*
 * mise en place d'un tube anonyme ou un père
 * communique avec son fils.
 * le père déclare le tube, cré un fils (avec fork),
 * puis écrit dans le tube (la donnée est le tableau de char "message").
 * Le fils hérite du tube et lit dedans les données
 * en provenance du père.
 */
int main()
{
    char message[25] = "Cela provient d'un tube\n";
    // déclaration du tableau de descripteur
    int p[2];

    // appel de la primitive "pipe"
    if (pipe(p) == -1) {
        fprintf(stderr, "erreur à l'ouverture par la fonction pipe\n");
        return 1;
    }

    if (fork() == 0)/* fils */
    {
        char c;
        close(p[1]);
        while (read(p[0], &c, 1) != 0)
            printf("%c", c);
        close(p[0]);
        return 0;
    }
    else /* suite pere */
    {
        close(p[0]);
        write(p[1], message, 24);
        close(p[1]);
        int status;
        waitpid(-1, &status, 0); // attente de la fin de tous les fils.
        return 0;
    }
}
