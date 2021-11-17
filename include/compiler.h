#ifndef _compiler_h_
#define _compiler_h_

#include "../include/parser.h"
#include "../include/flags.h"

int compile(const list* cmd);

//aux
c_flags check_errors_in_assignment(const CMD* cmd);
int is_assignment_line(const CMD* line);
int command_count(const CMD* line);
int is_valid_type(const char* type);
char** data_types();
void free_string_array(char** array);

#endif
