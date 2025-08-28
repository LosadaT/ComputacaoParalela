//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n = 7;
    pid_t pid;
    printf("Eu sou o pai!\n");
    for (int i = 0; i<n; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Fork falhou\n");
            return 1;
        }
        if (pid == 0) {
            printf ("Eu sou o filho! Meu PID e %d ,meu pai e %d.\n ", getpid(), getppid());
            exit(0);
        }
    }  
    
    for (int i = 0; i<n; i++ ) {
        wait(NULL);
    } 
    return 0;
}
