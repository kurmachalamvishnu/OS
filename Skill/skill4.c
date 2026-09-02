#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


#define MAX_ARGS 10

int main() {
    char input[100];
    char *args[MAX_ARGS];
    char *token;
    int i;

    while (1) {
        printf("myshell> ");
        fgets(input, sizeof(input), stdin);

        // Remove newline
        input[strcspn(input, "\n")] = '\0';

        // Exit condition
        if (strcmp(input, "exit") == 0)
            break;

        // Tokenize input
        i = 0;
        token = strtok(input, " ");
        while (token != NULL && i < MAX_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; // execvp expects NULL-terminated array

        if (args[0] == NULL) continue; // Empty input

        // Fork and execute command
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror("execvp failed"); // If exec fails
            exit(1);
        } else {
            // Parent waits
            wait(NULL);
        }
    }

    return 0;
}
