#include <stdlib.h>

#include "../include/string.h"
#include "../include/linked_list.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strcmp(char *s1, const char *s2)
{
	int	index;

	index = 0;
	while (s2[index] && s1[index] == s2[index])
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

char	*ft_strcpy(char *dest, const char *src)
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

char	*ft_strlcpy(char *dest, const char *src, unsigned int n)
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

list	*ft_split_line(const char *str)
{
	list*		lines;
	list*		line;
	unsigned int	w_size;
	
	lines = 0;
	while (*str)
	{
		line = 0;
		w_size = 0;
		while (*str != '\n')
		{
			while (_isspace(*str)) str++;
			if (*str == '\n') break ;
			w_size = *str == ';'? 1: _first_space(str) - str;
			pushc(&line, (void *)ft_strlcpy(malloc(++w_size), str, w_size));
			str += --w_size;
		}
		if (w_size) pushc(&lines, (void *)line);
		str++;
	}
	return (lines);
}

int	_isspace(char c)
{
	return (c != '\n' && (c >= '\t' && c <= '\r') || c == ' ');
}

char	*_first_space(const char *str)
{
	while (*str && !_isspace(*str) && *str != '\n' && *str != ';')
		str++;
	return ((char*)str);
}
/*
#include <stdio.h>

int	main(void)
{
	list* a;
	list* b;

	a = ft_split_line(" \n      integer a; -< 5; ssd sdf; sdf sdf\n string name <- \"Arbiyski\";    \n                      \nfloat pi <- 3.14;\n\n\n");
	b = (list *)a->value;
	for (int l = 1; a; a = a->next, l++)
	{
		b = (list*)a->value;
		printf("%d. line: ", l);
		for (; b; b = b->next)
			printf("%s ", (char*)b->value);
		printf("\n");
	}
	printf("The End!\n");
	return (0);
}*/
