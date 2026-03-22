#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct commandType {
    char command[100];
    char paramater[100];
} command_t;

command_t *parser(char * commandStr) {
    command_t *cmd = (command_t *)malloc(sizeof(command_t));
 command_t *parser(char * commandStr) {
    command_t *cmd = (command_t *)malloc(sizeof(command_t));
    sscanf(commandStr, "%s", cmd->command);
    int x = strlen(cmd->command)+1;
    sscanf(commandStr+x, "%[^\n]", cmd->paramater);
    return cmd;
}
   

int main() {
    char commandStr[256]={0};
    command_t *cmd=NULL;
    do {
        printf("MyShell%% ");
        fgets(commandStr, sizeof(commandStr), stdin);
        cmd = parser(commandStr);
        printf("cmd->command = %s\n",cmd->command);
        printf("cmd->parameter = %s\n", cmd->paramater);
        free(cmd);
    } while (strcmp(commandStr, "quit") != 0);
}
