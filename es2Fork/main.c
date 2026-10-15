#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid1 = fork(), pid2 = fork(), pid3 = fork();

    if (pid1 == -1 || pid2 == -1 || pid3 == -1) {
        perror("fork");
        return 1;
    }

    if (pid1 == 0) {
        printf("Processo figlio 1: PID = %d\n", getpid());
        sleep(2);
        return 0;
    } else if (pid2 == 0) {
        printf("Processo figlio 2: PID = %d\n", getpid());
        sleep(2);
        return 0;
    } else if (pid3 == 0) {
        printf("Processo figlio 3: PID = %d\n", getpid());
        sleep(2);
        return 0;
    } else {
        wait(NULL);
        wait(NULL);
        wait(NULL);
        printf("Processo padre dopo che tutti i processi figli sono terminati: PID = %d\n", getpid());
    }

    return 0;
}
