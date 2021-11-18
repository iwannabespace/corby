#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "../include/types.h"
#include "../include/parser.h"
#include "../include/string.h"

list	*ft_parse(const char *fname)
{
	char*	buf;
	int		line;
	list*	lst;
	list*	temp;
	CMD*	cmd;
	list*	l2;

	line = 1;
	buf = _readf(fname, 1024);
	lst = ft_split_line(buf);
	temp = lst;
	while(lst)
	{
		cmd = malloc(sizeof(CMD));
		cmd->value = (list*)lst->value;
		cmd->line = line++;
		lst->value = (void*)cmd;
		lst = lst->next;
	}
	return (temp);
}

char	*_readf(const char *fname, int size)
{
	char	c;
	char	*buf;
	int	fd;
	int	index;
	int	readed;

	buf = malloc(size + 1);
	fd = open(fname, O_RDONLY);
	if (!fd) return (0);
	index = 0;
	readed = 1;
	while (readed && index < size)
	{
		readed = read(fd, &c, 1);
		buf[index++] = c;
	}
	buf[index] = '\0';
	return (buf);
}

#include <stdio.h>

int	main(void)
{
	list* 	a;
	list* 	b;
	CMD*	c;

	a = ft_parse("e.corby");
	for (; a; a = a->next)
	{
		c = (CMD*)a->value;
		b = c->value;
		printf("%d. line: ", c->line);
		for (; b; b = b->next)
				printf("%s ", (char*)b->value);
		printf("\n");
	}
	printf("The End!\n");
	return (0);
}

