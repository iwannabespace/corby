#include "../include/compiler.h"
#include <stdio.h>

int compile(const CMD* cmd)
{
    for (int i = 0; cmd[i].type; i++)
    {    
        printf("name: %s\noperator: %s\nvalue: %s\n", cmd[i].name, cmd[i].oprt, cmd[i].value);

        if (!*cmd[i].name || !*cmd[i].oprt || !*cmd[i].value)
            return 0;
    }

    return 1;
}

int main(int argc, char** argv)
{
    CMD* cmd = ft_parse(argv[1]);

    printf("%d\n", compile(cmd));

    return 0;
}