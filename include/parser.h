#ifndef _parser_h_
#define _parser_h_

#include "types.h"
#include "linked_list.h"

list* ft_parse(const char* fname);

//aux
char	*_readf(char *fname, int size);
int	_cmd_count(char **buf);
int	_define_variable(CMD *cmd, char **buf, int size);

#endif
