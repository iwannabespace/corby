#include "../include/compiler.h"
#include "../include/string.h"
#include <stdio.h>

int is_assignment_line(const CMD* line)
{
    for (int i = 0; line->command_list[i]; i++)   
        if (ft_strcmp(line->command_list[i], "<-") == 0)
            return 1;

    return 0;
}

int compile(const list* list)
{
    while (list)
    {
        CMD* cmd = (CMD*)list->value; 

        if (is_assignment_line(cmd))
        {    
            if (check_errors(cmd))
                printf("Error in line %d\n", cmd->line_number);
        }

        else
            printf("Warning: Unknown line -> {line number: %d}\n", cmd->line_number);

        list = list->next;
    }

    return 0;
}

c_flags check_errors_in_assignment(const CMD* cmd)
{
    if (command_count(cmd) != 4)
        return INSUFFICIENT_COMMAND_ERROR;

    if (!is_valid_type(cmd->command_list[0]))
        return INVALID_TYPE_ERROR;

    return NO_ERROR;
}

int is_valid_type(const char* type)
{
    char** types = data_types();

    for (int i = 0; i < 4; i++)
        if (ft_strcmp(type, types[i]) == 0)
        {
            free_string_array(types);
            return 1;
        }

    free_string_array(types);

    return 0;
}

char** data_types()
{
    char** types = malloc(sizeof(char*) * 4);
    
    for (int i = 0; i < 4; i++)
        types[i] = malloc(sizeof(char) * 10);

    ft_strcpy(types[0], "integer");
    ft_strcpy(types[1], "float");
    ft_strcpy(types[2], "string");
    ft_strcpy(types[3], "boolean");

    return types;
}

int command_count(const CMD* cmd)
{
    int i = 0;

    for (; cmd->command_list[i]; i++) {}

    return i;
}

void free_string_array(char** array)
{
    for (int i = 0; i < 4; i++)
        free(array[i]);
    
    free(array);
}

int main(int argc, char** argv)
{
    CMD cmd;

    cmd.line_number = 0;

    cmd.command_list = malloc(sizeof(char*) * 4);

    for (int i = 0; i < 4; i++)
        cmd.command_list[i] = malloc(10);
    
    ft_strcpy(cmd.command_list[0], "integer");
    ft_strcpy(cmd.command_list[1], "val");
    ft_strcpy(cmd.command_list[2], "<-");
    ft_strcpy(cmd.command_list[3], "10");

    printf("%d\n", is_assignment_line(&cmd));

    return 0;
}
