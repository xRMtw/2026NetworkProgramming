#ifndef __PARSER__
#define __PARSER__

typedef struct commandType {
    char command[100];
    char paramater[100];
} command_t;

command_t *parser(char * commandStr) {}

#endif