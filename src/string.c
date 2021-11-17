#include <stdlib.h>
#include <stdio.h>

#include "../include/string.h"

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

char	***ft_split(char *str)
{
	char	**array;
	char	**result;
	int	count_words;
	int	w_size;

	count_words = _count_words(str);
	array = malloc(sizeof(char **) * (count_words + 1));
	result = array;
	for (int i = 0; i < count_words; i++)
	{
		while (_isspace(*str))
			str++;
		w_size = _first_space(str) - str;
		if (!w_size)
			break ;
		printf("%d ", w_size);
		*array = malloc(++w_size);
		ft_strlcpy(*array++, str, w_size);
		printf("%s(%d)\n", *(array - 1), ft_strlen(*(array - 1)));
		str += --w_size;
	}
	*array = 0;
	return (result);
}

int	_count_words(char *str)
{
	int	index;
	int	count;

	count = 0;
	index = 0;
	while (str[index])
	{
		while (_isspace(str[index]))
			index++;
		count += str[index] != 0;
		while (!_isspace(str[index]) && str[index])
			index++;
	}
	return (count);
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
	while (!_isspace(*str))
		str++;
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char **a;

	a = ft_split("       integer a = 5 ;\n     \n\n\n\n\n");
	for (int i = 0; a[i]; i++)
		printf("%s", a[i]);

	return (0);
}*/
