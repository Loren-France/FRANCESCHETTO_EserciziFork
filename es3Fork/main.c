#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {

    pid_t padre = fork();

    if (padre == -1) {
        perror("fork");
        return 1;
    }
    else if (padre == 0) {
        pid_t figlio = fork();

        if (figlio == -1) {
            perror("fork");
            return 1;
        }
        else if (figlio == 0) {
            printf("Sono il figlio e termino con questo messaggio di chiusura.\n");
            exit(0);
        }
        else {
            wait(NULL);
        }

        printf("Sono il padre e termino con questo messaggio di chiusura.\n");
        exit(0);
    }
    else {
        wait(NULL);
    }

    printf("Sono il processo principale cioè il padre del padre (Nonno) e termino con questo messaggio di chiusura.\n");

    return 0;
}
