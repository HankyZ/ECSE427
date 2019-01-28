#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shellmemory.h"
#include "shell.h"

int help(int num_words, char* words[])
{
    if (num_words > 1)
        return 2;
    printf("The available commands are:\n");
    printf("help, quit, set, print, run\n");
    return 0;
}

int quit(int num_words, char* words[])
{   
    if (num_words > 1)
        return 2;
    printf("Bye!\n");
    exit(99);
    return 0;
}

int set(int num_words, char* words[])
{
    if (num_words > 3)
        return 2;

    int errCode = store(words[1], words[2]);
    if (errCode != 0)
        return errCode;

    printf("Stored var %s\n", words[1]);
    return 0;
}

int print(int num_words, char* words[])
{    
    if (num_words > 2)
        return 2;
    printf("%s\n", extract(words[1]));
    return 0;
}

int run(int num_words, char* words[])
{    
    if (num_words > 2)
        return 2;
    int errCode = 0;
    char* line;
    FILE *fp = fopen(words[1], "rt");
    if (fp == NULL)
        return 4;
    size_t len = 999;
    while (getline(&line, &len, fp))
    {
        errCode = parse(line);
        if (errCode != 0)
        {
            fclose(fp);
            return errCode;
        }
    }
    fclose(fp);
    return errCode;
}

int interpreter(int num_words, char* words[])
{
    int errCode = 0;
    if (!strcmp(words[0], "help"))
        errCode = help(num_words, words);
    else if (!strcmp(words[0], "quit"))
        errCode = quit(num_words, words);
    else if (!strcmp(words[0], "set"))
        errCode = set(num_words, words);
    else if (!strcmp(words[0], "print"))
        errCode = print(num_words, words);
    else if (!strcmp(words[0], "run"))
        errCode = run(num_words, words);
    else
        errCode = 1;
    return errCode;
}




