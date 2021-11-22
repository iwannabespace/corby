#ifndef _dict_h_
#define _dict_h_

#include "linked_list.h"
#include "string.h"

typedef struct s_dict
{
	char*	key;
	void*	value;
} dict;

void*	where_key(list* dicts, char *key);
void*	where_index(list* dicts, unsigned int index);

#endif