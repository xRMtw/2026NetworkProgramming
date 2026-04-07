#include "header.h"
#include "parser.h"
#include "buildin.h"

char PATH[] = "bin:.";

void mysetenv ( char* var, char* val ) {
    if( strcmp( var, "PATH" ) == 0 ) {
        strcpy( PATH, val );
    }
    else {}
}

void printenv ( char* var ) {
    if( strcmp( var, "PATH" ) == 0 ) {
        printf( "%s\n", PATH );
    }
    else {}
}

int main() {
    char commandStr[256]={0};
    command_t *cmd=NULL;
    while( 1 ) {

        printf("MyShell%% ");
        fgets(commandStr, sizeof(commandStr), stdin);

        if( strncmp( commandStr, "quit", 4 ) == 0 ) {
            break;
        }

        cmd = parser(commandStr);

        if( strcmp( cmd->command, "printenv" ) == 0 ) {
            printenv( cmd->paramater );
        }
        else if( strcmp( cmd->command, "setenv" ) == 0 ) {
            command_t* tmp = NULL;

            tmp = parser( cmd->paramater );
            mysetenv( tmp->command, tmp->paramater );
            free(tmp);
        }
        else {

            // struct dirent *de;
            // DIR *dr = opendir( PATH );
            // int found = 0;

            // if( dr == NULL ) {
            //     printf( "Unknown command: [%s].\n",cmd->command );
            // }
            // else {
                
                //search file in PATH
                // while( ( ( de = readdir(dr) ) != NULL ) ) {

                    //if( strcmp( de->d_name, cmd->paramater ) == 0 ) {
                        //found = 1;
                        pid_t childPid;

                        //fork a child to process
                        switch ( childPid = fork() ) {
                            case -1:
                                perror("Can't fork\n");
                                exit(EXIT_FAILURE);
                                
                            case 0:
                                sleep(0.5);
                                execlp(PATH, cmd->command, cmd->paramater, NULL );
                                exit(EXIT_SUCCESS);

                            default:
                                int status;
                                pid_t ret;
                                ret = wait(&status);
                                if( WIFEXITED(status) ) 
                                {
                                    ret = WEXITSTATUS(status);
                                } 
                                else if( WIFSIGNALED(status) )
                                {
                                    ret = WTERMSIG(status);
                                }
                                break;
                            
                            
                        }

                    //}
                    //else {}

                //}
                
                // if( !found )
                //     printf( "Unknown command: [%s].\n",cmd->command );
                // else {}

            //}

            //closedir( dr );
        }

        free(cmd);

    }
}