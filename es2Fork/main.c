#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int GestioneProcesso(pid_t pid) {
    static int count = 0;
    count++;
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {
        printf("Processo figlio %d: PID = %d\n", count, getpid());
        sleep(2);
        exit(0);
    }
    else {
        wait(NULL);
    }
    return 0;
}

int main(void) {
    pid_t pid1 = fork();

    GestioneProcesso(pid1);

    pid_t pid2 = fork();

    GestioneProcesso(pid2);

    pid_t pid3 = fork();

    GestioneProcesso(pid3);

    printf("Processo padre dopo la conclusione dei figli: PID = %d\n", getpid());

    return 0;
}
