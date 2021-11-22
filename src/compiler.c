#include "../include/compiler.h"
#include "../include/string.h"
#include "../include/colorizer.h"
#include "../include/valid_value.h"

#include <stdio.h>

c_result compile(const list* data)
{
    const list* data_copy = data;
    int error_count = 0;
    int warning_count = 0;

    while (data)
    {
        CMD* line = data->value; 
        c_flags error = check_line(line, data_copy);

        set_text_color(RED);
        switch (error)
        {
            case MISSING_SEMICOLON_ERROR:
                printf("Error: Missing semicolon in line %d\n", line->line);
                error_count++;
                break;

            case TOKEN_OVERFLOW_ERROR:
                printf("Error: Extra tokens in line %d\n", line->line);
                error_count++;
                break;

            case INSUFFICIENT_COMMAND_ERROR:
                printf("Error: Insufficient tokens in assignment line %d\n", line->line);
                error_count++;
                break;
            
            case INVALID_TYPE_ERROR:
                printf("Error: Invalid type in assignment line %d\n", line->line);
                error_count++;
                break;

            case INVALID_VALUE_ERROR: 
                printf("Error: Invalid value for type '%s' in assignment line %d\n", line->value->value, line->line);
                error_count++;
                break;

            case VARIABLE_NAME_ALREADY_EXISTS_ERROR:    
                printf("Error: Variable name already exits for line %d\n", line->line);
                error_count++;
                break;

            case WARNING:   
                set_text_color(YELLOW);
                printf("Warning: Uncompilable line -> {line number: %d}\n", line->line);
                warning_count++;
                break;

            default:
                set_text_color(BLUE);
                printf("Line %d is okay!\n", line->line);
                break;
        }
        set_text_color(RESET);

        data = data->next;
    }

    return (c_result){ error_count, warning_count };
}

c_flags check_line(const CMD* line, const list* data)
{
    list* beg = line->value;
    list* temp = line->value;
    int is_assignment_line = 0;
    int is_semicolon_present = 0;
    int i = 0;
    int j = 0;

    for (; temp; temp = temp->next, j++)
    {    
        if (ft_strcmp(temp->value, ";") == 0)
            if (!is_semicolon_present)
            {
                i = j;
                is_semicolon_present = 1;
            }

        if (ft_strcmp(temp->value, "<-") == 0)
            is_assignment_line = 1;

    }
    temp = beg;
    j--;

    if (!is_semicolon_present)
        return MISSING_SEMICOLON_ERROR;

    if (i != j)
        return TOKEN_OVERFLOW_ERROR;

    if (is_assignment_line)
    {       
        char* value = temp->next->next->next->value;

        if (j != 4)
            return INSUFFICIENT_COMMAND_ERROR;

        else if (!is_valid_type(temp->value))
            return INVALID_TYPE_ERROR;

        else if (!is_appropriate_name(line, data))
            return VARIABLE_NAME_ALREADY_EXISTS_ERROR;

        else if ((ft_strcmp(temp->value, "integer") == 0 && !valid_int(value)) ||
                 (ft_strcmp(temp->value, "float") == 0 && !valid_float(value)) ||
                 (ft_strcmp(temp->value, "string") == 0 && !valid_string(value)) ||
                 (ft_strcmp(temp->value, "boolean") == 0 && !valid_boolean(value)))
            return INVALID_VALUE_ERROR;

        else 
            return NO_ERROR;
    }

    return WARNING;
}

int is_valid_type(char* type)
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

int is_assignment_line(const CMD* line)
{
    for (list* line_val = line->value; line_val; line_val = line_val->next)
        if (ft_strcmp(line_val->value, "<-") == 0)
            return 1;

    return 0;
}

int is_appropriate_name(const CMD* line, const list* data)
{    
    for (; data; data = data->next)
    {
        CMD* line_ = data->value;
        list* tokens = line_->value;

        if (is_assignment_line(line_) && line->line > line_->line)
            if (ft_strcmp(line->value->next->value, tokens->next->value) == 0)
            {    
                return 0;
            }
    }

    return 1;
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
    c_result result = compile(data);

    if (result.error_count == 0)
    {
        set_text_color(GREEN);

        if (result.warning_count == 0)
            printf("Compilation successfull!\n");

        else
        {
            if (result.warning_count > 1)
                printf("%d warnings are found\nCompilation successfull!\n", result.warning_count);

            else
                printf("%d warning is found\nCompilation successfull!\n", result.warning_count);
        }

        set_text_color(RESET);
    }

    else
    {
        set_text_color(MAGENTA);

        if (result.error_count > 1)
        {
            if (result.warning_count > 1)
                printf("%d errors and %d warnings are found\nCompilation failed!\n", result.error_count, result.warning_count);
            
            else
                printf("%d errors and %d warning are found\nCompilation failed!\n", result.error_count, result.warning_count);
        }

        else
        {
            if (result.warning_count > 1)
                printf("%d error and %d warnings are found\nCompilation failed!\n", result.error_count, result.warning_count);
            
            else
                printf("%d error and %d warning are found\nCompilation failed!\n", result.error_count, result.warning_count);
        }

        set_text_color(RESET);
    }

    return 0;
}
