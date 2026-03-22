#include "header.h"
#include "parser.h"

int main() {
    char commandStr[256]={0};
    command_t *cmd=NULL;
    do {
        printf("MyShell%% ");
        fgets(commandStr, sizeof(commandStr), stdin);
        cmd = parser(commandStr);
        printf("cmd->command = %s\n",cmd->command);
        printf("cmd->parameter = %s\n", cmd->paramater);
        
        if( cmd->command == "printenv" ) {

        }
        else if( cmd->command == "setenv" ) {

        }
        free(cmd);
    } while (strcmp(commandStr, "quit\n") != 0);
}

