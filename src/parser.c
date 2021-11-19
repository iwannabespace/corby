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

	buf = _readf(fname, 1024);
	return (ft_split_line(buf));
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
