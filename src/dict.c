#include "../include/dict.h"

void*	where_key(list* dicts, char* key)
{
	dict*	dict_t;

	while (dicts)
	{
		dict_t = (dict*)dicts->value;
		if (!ft_strcmp(dict_t->key, key))
			return ((dict_t->value));
		dicts = dicts->next;
	}
	return (0);
}

void*	where_index(list* dicts, unsigned int index)
{
	unsigned int jndex;

	jndex = 0;
	while (dicts && (jndex != index))
	{
			dicts = dicts->next;
			jndex++;
	}
	if (dicts && jndex == index)
		return (((dict*)dicts->value)->value);
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main()
{
	list*	liste;
	dict*	dicte;

	liste = malloc(sizeof(list));
	dicte = malloc(sizeof(dict));
	dicte->key = strdup("A");
	dicte->value = (void*)strdup("is A");
	liste->value = (void*)dicte;
	liste->next = malloc(sizeof(list));
	dicte = malloc(sizeof(dict));
	dicte->key = strdup("B");
	dicte->value = (void*)strdup("is B");
	liste->next->value = (void*)dicte;
	liste->next->next = 0;

	printf("%s\n", (char *)where_index(liste, 0));
	printf("%s\n", (char *)where_key(liste, "B"));

	return (0);
}*/
