#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {
        // Processo figlio
        for (int i = 1; i < 6; i++) {
            printf("%d\n", i);
            sleep(1);
        }
    }
    else {
        // Processo padre
        wait(NULL);
        for (int i = 6; i < 11; i++) {
            printf("%d\n", i);
            sleep(1);
        }
    }
    return 0;
}
