#ifndef _parser_h_
#define _parser_h_

#include "types.h"
#include "linked_list.h"

list* ft_parse(const char* fname);

//aux
char	*_readf(const char *fname, int size);

#endif
