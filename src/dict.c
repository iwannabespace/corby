#include "../include/dict.h"

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
