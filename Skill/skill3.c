#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main() {
    char *history[MAX];
    char command[100];
    int count = 0;

    while (1) {
        printf("shell> ");
        fgets(command, sizeof(command), stdin);

        // Remove newline
        command[strcspn(command, "\n")] = '\0';

        // Exit condition
        if (strcmp(command, "exit") == 0)
            break;

        // Print history
        if (strcmp(command, "history") == 0) {
            for (int i = 0; i < count; i++)
                printf("%d: %s\n", i + 1, history[i]);
            continue;
        }

        // Store command in history
        if (count < MAX) {
            history[count] = malloc(strlen(command) + 1);
            strcpy(history[count], command);
            count++;
        }
    }

    // Free allocated memory
    for (int i = 0; i < count; i++)
        free(history[i]);

    return 0;
}
