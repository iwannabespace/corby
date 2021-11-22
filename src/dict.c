#include "../include/dict.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"
#include "../include/compiler.h"

void*    where_key(list* dicts, char* key)
{
    dict*    dict_t;

    while (dicts)
    {
        dict_t = (dict*)dicts->value;
        if (!ft_strcmp(dict_t->key, key))
            return ((dict_t->value));
        dicts = dicts->next;
    }
    return (0);
}

void*    where_index(list* dicts, unsigned int index)
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
<<<<<<< HEAD

list*	get_variables_until(list* data, int line)
{
	list* dict_list = malloc(sizeof(list));
	dict* dicte = malloc(sizeof(dict));
	list* beg = dict_list;

	if (line == -1)
	{
		while (data)
		{
			CMD* cmd = data->value;
			list* tokens = cmd->value;

			if (is_assignment_line(cmd))
			{	
				dicte->key = strdup((char*)tokens->next->value);
				dicte->value = (void*)strdup((char*)tokens->next->next->next->value);
				dict_list->value = (void*)dicte;
				dict_list->next = malloc(sizeof(list));
				dict_list = dict_list->next;
				dicte = malloc(sizeof(dict));
			}

			data = data->next;
		}
	}	

	else if (line >= 1)
	{
		int i = 1;

		while (data && i <= line)
		{
			CMD* cmd = data->value;
			list* tokens = cmd->value;

			if ((i = cmd->line) > line)
				break;

			if (is_assignment_line(cmd))
			{	
				dicte->key = strdup((char*)tokens->next->value);
				dicte->value = (void*)strdup((char*)tokens->next->next->next->value);
				dict_list->value = (void*)dicte;
				dict_list->next = malloc(sizeof(list));
				dict_list = dict_list->next;
				dicte = malloc(sizeof(dict));
			}
			
			data = data->next;
		}
	}

	else
	{
		free(dict_list);
		free(dicte);
		return 0;
	}

	return beg;
}

int	main()
{
	list* data = ft_parse("e.corby");
	
	list* vars = get_variables_until(data, 3);

	while (vars)
	{
		dict* d = vars->value;

		printf("%s -> %s\n", d->key, (char*)d->value);

		vars = vars->next;
	}

	return (0);
}
=======
>>>>>>> aad0b5d8f172d933e2817bbadc5495e162f43ba2
