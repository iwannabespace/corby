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

	line = 1;
	buf = _readf(fname, 1024);
	lst = ft_split_line(buf);
	/*temp = lst;
	while(lst)
	{
		cmd = malloc(sizeof(CMD));
		cmd->value = (list*)lst->value;
		cmd->line = line++;
		lst->value = (void*)cmd;
		lst = lst->next;
	}*/
	return (lst);
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
