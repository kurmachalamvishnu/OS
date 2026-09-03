#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void child_handler(int sig) {
    printf("SIGCHLD received: Child has terminated\n");
    wait(NULL); // Clean up child process
}

int main() {
    // Register handler for SIGCHLD
    signal(SIGCHLD, child_handler);

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child is running...\n");
        sleep(2);
        printf("Child is exiting...\n");
    } else {
        // Parent process
        printf("Parent is waiting...\n");
        sleep(5);
        printf("Parent finished.\n");
    }

    return 0;
}
