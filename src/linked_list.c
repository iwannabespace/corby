#include "../include/linked_list.h"

list* create_list()
{
    return malloc(sizeof(list));
}

void push(list* l, const char* value)
{
    

    while (l)
        l = l->next;
}

char* get(const list* l);

void delete_list(list* l)
{
    list* temp;

    while (l)
    {
        temp = l->next;
        free(l->value);
        free(l);
        l = temp;
    }
}