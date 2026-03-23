#include "header.h"
#include "parser.h"
#include "buildin.h"

int main() {
    char commandStr[256]={0};
    command_t *cmd=NULL;
    do {
        printf("MyShell%% ");
        fgets(commandStr, sizeof(commandStr), stdin);
        cmd = parser(commandStr);
        printf("cmd->command = %s\n",cmd->command);
        printf("cmd->parameter = %s\n", cmd->paramater);
        
        if( strcmp( cmd->command, "printenv" ) == 0 ) {
            printenv( cmd->paramater );
        }
        else if( strcmp( cmd->command, "settenv" ) ) {
            command_t* tmp = NULL;

            tmp = parser( cmd->paramater );
            settenv( tmp->command, tmp->paramater );
            free(tmp);
        }
        else {
            //find in PATH in bin
            //if find fork
            //else Unknown command: [command].
        }

        free(cmd);
    } while (strcmp(commandStr, "quit\n") != 0);
}

