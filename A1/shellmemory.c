#include <string.h>

char* mem[1000][2];

int store(char* var, char* val)
{
    for (int i = 0; i < 1000; i++)
    {
        if (mem[i][0] == NULL)
        {
            mem[i][0] = strdup(var);
            mem[i][1] = strdup(val);
            return 0;
        }
        if (!strcmp(mem[i][0], var))
        {
            mem[i][1] = val;
            return 0;
        }
    }
    return 3;
}

char* extract(char* var)
{
    char* err_msg = "Variable does not exist";
    for (int i = 0; i < 1000; i++)
    {
        if (mem[i][0] == NULL)
            return err_msg;
        if (!strcmp(mem[i][0], var))
            return mem[i][1];
    }
    return err_msg;
}
