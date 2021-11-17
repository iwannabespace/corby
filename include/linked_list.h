#ifndef _linked_list_h_
#define _linked_list_h_

#include <stdlib.h>

typedef struct s_list
{
    void* value;
    struct s_list* prev;
    struct s_list* next;
} list;

list* create_list();
void push(list* l, void* value);
void* get(const list* l);
void delete_list(list* l);

#endif
