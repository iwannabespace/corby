#include "../include/compiler.h"
#include "../include/string.h"
#include <stdio.h>

int is_assignment_line(const CMD* line)
{
    for (list* line_val = line->value; line_val; line_val = line_val->next)
        if (ft_strcmp(line_val->value, "<-") == 0)
            return 1;

    return 0;
}

int compile(const list* l)
{
    while (l)
    {
        CMD* line = l->value; 

        if (is_assignment_line(line))
        {    
            if (check_errors_in_assignment(line))
                printf("Error in line %d\n", line->line);
        }

        else
            printf("Warning: Unknown line -> {line number: %d}\n", line->line);

        l = l->next;
    }

    return 0;
}

c_flags check_errors_in_assignment(const CMD* line)
{
    list* temp = line->value;

    printf("command_count: %d\n", command_count(line));
    printf("is_valid_type: %d\n", is_valid_type(temp->value));

    if (command_count(line) != 5)
        return INSUFFICIENT_COMMAND_ERROR;

    if (!is_valid_type(temp->value))
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

int command_count(const CMD* line)
{
    int i = 0;

    for (list* line_val = line->value; line_val; line_val = line_val->next) 
        i++;

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
    list* data = ft_parse("e.corby");
    compile(data);

    return 0;
}
