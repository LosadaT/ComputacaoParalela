#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

#define NUM_PROCESSES 4

int main() {
    int vetor[1000];
    double soma = 0;
    int pipes[NUM_PROCESSES][2];
    double total_sum = 0;

    for (int i = 0; i < 1000; i++) {
        vetor[i] = 1;
    }

    for (int i = 0; i < NUM_PROCESSES - 1; i++) {
        pid_t pid = fork();
        pipe(pipes[i]);

        if (pid > 0) {
            close(pipes[i][1]);
                        exit(0);

        }
        else {
            close(pipes[i][0]);
            soma = soma+1;
            write(pipes[i][1], &soma, sizeof(double));
            exit(0);

        }
    }
    for (int i = 0; i < NUM_PROCESSES - 1; i++) {
        read(pipes[i][0],&soma, sizeof(double));
        total_sum = soma + total_sum;
        close(pipes[i][0]);
    }

    for(int i = 0; i < NUM_PROCESSES; i++) {
        wait(NULL);
    }

    printf("\n%f\n", total_sum);

}