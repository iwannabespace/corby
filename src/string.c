#include <stdlib.h>
#include <stdio.h>

#include "../include/string.h"
#include "../include/linked_list.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s2[index] && s1[index] == s2[index])
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int index;

	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (src[index] && index < n - 1)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

list	*ft_split_line(char *str)
{
	list*		lines;
	list*		line;
	list*		temp;
	char*		string;
	unsigned int	w_size;
	
	lines = create_list();
	lines->prev = 0;
	lines->next = 0;
	while (*str)
	{
		w_size = 0;
		line = create_list();
		temp = line;
		while (*str != '\n')
		{
			while (_isspace(*str))
				str++;
			if (*_first_space(str) == '\n')
				break ;
			w_size = _first_space(str) - str;
			string = malloc(++w_size);
			ft_strlcpy(string, str, w_size);
			line->value = string;
			line->next = create_list();
			line = line->next;
			str += w_size;
		}
		if (w_size)
			push(lines, (void *)temp);
		str++;
	}
	return (lines);
}

int	_isspace(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	_is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char	*_first_space(char *str)
{
	while (*str && !_isspace(*str) && *str != '\n')
		str++;
	return (str);
}

#include <stdio.h>

int	main(void)
{
	list* a;
	list* b;

	a = ft_split_line("       integer a = 5 ssd sdf; sdf sdf\n     \n\n\n\n\n");
	b = (list *)a->value;
	for (int i = 0; b; i++)
	{
		printf("eleman = %s\n", (char *)b->value);
		b = b->next;
	}

	return (0);
}
