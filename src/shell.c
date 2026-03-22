#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char commandStr[256]={0};
    do {
        printf("MyShell%% ");
        fgets(commandStr, sizeof(commandStr), stdin);
        printf("%s", commandStr);
    } while (strcmp(commandStr, "quit\n") != 0);
}
