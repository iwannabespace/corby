#include "../include/linked_list.h"
#include "../include/string.h"

list* create_list()
{
    return malloc(sizeof(list));
}

void push(list* l, void* value)
{
	list	new_l;
	int	size;

	new_l = malloc(list);
	while (l->next)
		l = l->next;
	new_l->value = value;
	l->next = new_l;
	new_l->prev = l;
	new_l->next = 0;
}

void* get(const list* l)
{
	return (l->value);
}

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

unsigned int	list_len(list* l)
{
	unsigned int	len;

	len = 0;
	while (l)
	{
		l = l-next;
		len++;
	}
	return (len);

}
