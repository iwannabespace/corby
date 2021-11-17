#ifndef TYPES_H
# define TYPES_H

typedef struct s_command
{
	char	*type;
	char	*name;
	char	*oprt;
	char	*value;
} CMD;

typedef struct commands
{
	int line_number;
	char** command_list;
} CMD2;

#endif
