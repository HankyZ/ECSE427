#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"

int parse(char input[])
{
    if (strlen(input) <= 1)
        return 0;
    // remove '\n' from end of string
    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        if (input[i] == '\n')
            input[i] = '\0';
    }
    char* words[1000];
    char* delim = " ";
    char* token = strtok(input, delim);

    int i = 0;
    while (token)
    {
        words[i++] = strdup(token);
        token = strtok(0, delim);
    }

    return interpreter(i, words);
}

int main(int argc, char* argv[])
{
    char prompt[100] = {'$', '\0'};
    char input[1000];
    int errorCode = 0;

    printf("Welcome to the Hank Zhang shell!\n");
    printf("Version 1.0 created January 2019\n");

    while ()
    {
        printf("%s ", prompt);
        fgets(input, 999, stdin);
        errorCode = parse(input);
        switch (errorCode)
        {
            case -1:
                printf("Fatal error\n");
                exit(99);
                break;
            case 1:
                printf("Unknown command\n");
                break;
            case 2:
                printf("Illegal number of arguments\n");
                break;
            case 3:
                printf("Memory full\n");
                break;
            case 4:
                printf("Script not found\n");
            default:
                break;
        }
    }
    return 0;
}
