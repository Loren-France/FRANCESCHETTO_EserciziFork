#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int ControlloPrimo(int numero) {
    if (numero <= 1) {
        return 0;
    }
    for (int i = 2; i <= numero / 2; i++) {
        if (numero % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    pid_t pid = fork();
    int status;

    if (pid == -1) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {
        printf("Sono il processo figlio e verifico il numero immesso.\n");
        int numero;
        printf("Inserisci un numero: ");
        scanf("%d", &numero);

        if (ControlloPrimo(numero)) {
            exit(1);
        }
        else if (numero % 2 == 0) {
            exit(2);
        }
        else {
            exit(3);
        }
    }
    else {
        wait(&status);
    }

    status = WEXITSTATUS(status);

    if (status == 1) {
        printf("Sono il processo padre e il numero immesso è primo.\n");
    }
    else if (status == 2) {
        printf("Sono il processo padre e il numero immesso è pari.\n");
    }
    else if (status == 3) {
        printf("Sono il processo padre e il numero immesso è dispari.\n");
    }
    else {
        printf("Errore nel processo figlio.\n");
    }
    return 0;
}
