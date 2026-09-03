#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigpipe(int sig) {
    printf("\nSIGPIPE received!\n");
    printf("The reading end of the pipe is closed.\n");
    exit(1);
}

int main() {
    int fd[2];

    // Register handler for SIGPIPE
    signal(SIGPIPE, handle_sigpipe);

    // Create pipe
    pipe(fd);
    printf("Pipe created.\n");

    // Close the reading end
    close(fd[0]);
    printf("Reading end closed.\n");

    // Attempt to write to the pipe
    printf("Trying to write to the pipe...\n");
    write(fd[1], "Hello", 5);
    printf("Write completed.\n");

    return 0;
}
