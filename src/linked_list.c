#include "../include/linked_list.h"
#include "../include/string.h"

list* create_list()
{
	list*	l;

	l = malloc(sizeof(list));
	l->value = 0;
	l->next = 0;
	l->prev = 0;
	return (l);
}

void push(list* l, void* value)
{
	list*	new_l;

	new_l = create_list();
	while (l->next)
		l = l->next;
	new_l->value = value;
	l->next = new_l;
	new_l->prev = l;
}

void	pushc(list** l, void* value)
{
	list*	new_l;
	if (*l)
		return push(*l, value);
	*l = create_list();
	(*l)->value = value;
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
		l = l->next;
		len++;
	}
	return (len);

}
