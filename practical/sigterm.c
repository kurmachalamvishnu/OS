#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    if (sig == SIGTERM) {
        printf("\nSIGTERM received!\n");
    }
}

int main() {
    // Register handler for SIGTERM
    signal(SIGTERM, handler);

    // Print process ID so you know which PID to send SIGTERM to
    printf("Process ID: %d\n", getpid());
    printf("Waiting for SIGTERM...\n");

    while (1) {
        sleep(2); // Keeps program alive until signal is received
    }

    return 0;
}
