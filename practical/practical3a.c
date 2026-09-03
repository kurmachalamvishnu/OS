#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child Process\n");
        printf("PID  : %d\n", getpid());
        printf("PPID : %d\n", getppid());
        sleep(10);
    } else if (pid > 0) {
        // Parent process
        printf("Parent Process\n");
        printf("PID  : %d\n", getpid());
        wait(NULL);  // Wait for child to finish
    } else {
        // Fork failed
        perror("fork failed");
        return 1;
    }

    return 0;
}
