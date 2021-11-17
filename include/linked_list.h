#ifndef _linked_list_h_
#define _linked_list_h_

#include <stdlib.h>

typedef struct s_list
{
    void* value;
    s_list* prev;
    s_list* next;
} list;

list* create_list();
void push(list* l, void* value);
void* get(const list* l);
void delete_list(list* l);

#endif
