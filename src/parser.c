#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "../include/types.h"
#include "../include/parser.h"
#include "../include/string.h"

CMD	*ft_parse(char *fname)
{
	int	res_len;
	char	*buf1;
	char	**buf;
	CMD	*result;

	buf1 = _readf(fname, 1024);
	buf = ft_split(buf1);
	res_len = _cmd_count(buf);
	result = malloc(sizeof(CMD) * (res_len + 1));
	if (!_define_variable(result, buf, res_len))
		return (0);
	result[res_len] = (CMD){0, 0, 0, 0};
	return (result);
}

char	*_readf(char *fname, int size)
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

int	_cmd_count(char **buf)
{
	int	count;

	count = 0;
	while (*buf)
		if (!ft_strcmp(*buf++, ";")) count++;
	return (count);
}

int	_define_variable(CMD *cmd, char **buf, int size)
{
	int	index;
	int	w_size;

	index = 0;
	while (index < size)
	{
		if (!ft_strcmp(*buf, ";"))
			buf++;
		printf("len for \"%s\" is %d\n", *buf, ft_strlen(*buf));
		cmd->type = malloc(ft_strlen(*buf) + 1);
		ft_strcpy(cmd->type, *buf);
		printf("Type: %s, ", cmd->type);
		buf++;
		cmd->name = malloc(ft_strlen(*buf) + 1);
		ft_strcpy(cmd->name, *buf);
		printf("Name: %s, ", cmd->name);
		buf++;
		cmd->oprt = malloc(ft_strlen(*buf) + 1);
		ft_strcpy(cmd->oprt, *buf);
		printf("Operator: %s, ", cmd->oprt);
		buf++;
		cmd->value = malloc(ft_strlen(*buf) + 1);
		ft_strcpy(cmd->value, *buf);
		printf("Value: %s(%d)\n", cmd->value), ft_strlen(*buf);
		buf++;
		cmd++;
		index++;
	}
	printf("success\n");
	return (1);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	CMD	*a;

	if (argc < 2)
		return (0);

	a = ft_parse(argv[1]);
	printf("\n\n");
	for (int i = 0; a[i].type; a++)
	{
		printf("Type: %s, Name: %s, Operator: %s, Value: %s\n", a->type, a->name, a->oprt, a->value);
	}
	return (0);
}
