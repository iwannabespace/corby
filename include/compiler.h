#ifndef _compiler_h_
#define _compiler_h_

#include "../include/parser.h"
#include "../include/flags.h"

typedef struct t_result
{
    int error_count;
    int warning_count;
} c_result;

c_result compile(const list* data);

//aux
c_flags check_line(const CMD* line, const list* data);
int is_assignment_line(const CMD* line);
int is_appropriate_name(const CMD* line, const list* data);
int command_count(const CMD* line);
int is_valid_type(char* type);
char** data_types();
void free_string_array(char** array);

#endif
