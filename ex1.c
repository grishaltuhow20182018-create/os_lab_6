
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(void) {
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 == 0) {
        clock_t start = clock();
        printf("Child 1 PID: %d, Parent PID: %d\n", getpid(), getppid());
        clock_t end = clock();
        printf("Child 1 time: %.4f ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0);
        exit(0);
    }

    pid2 = fork();
    if (pid2 == 0) {
        clock_t start = clock();
        printf("Child 2 PID: %d, Parent PID: %d\n", getpid(), getppid());
        clock_t end = clock();
        printf("Child 2 time: %.4f ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0);
        exit(0);
    }

    clock_t start = clock();
    wait(NULL);
    wait(NULL);
    printf("Main PID: %d, Parent PID: %d\n", getpid(), getppid());
    clock_t end = clock();
    printf("Main time: %.4f ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0);

    return 0;
}
