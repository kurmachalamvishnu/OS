#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

int main() {
    struct termios oldt, newt;
    char buffer[100];
    int index = 0;
    char ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while (1) {
        index = 0;
        memset(buffer, 0, sizeof(buffer));

        printf("vishnu@VISHNU:~$ ");
        fflush(stdout);

        while (1) {
            ch = getchar();

            if (ch == '\n') {
                buffer[index] = '\0';
                break;
            } else if (ch == 127) {
                if (index > 0) {
                    index--;
                    printf("\b \b");
                    fflush(stdout);
                }
            } else {
                if (index < (int)sizeof(buffer) - 1) {
                    buffer[index++] = ch;
                    printf("%c", ch);
                    fflush(stdout);
                }
            }
        }

        if (strcmp(buffer, "exit") == 0) {
            printf("\nExiting shell...\n");
            break;
        }

        printf("\nYou entered: %s\n", buffer);
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return 0;
}
