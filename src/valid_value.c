#include <stdio.h>
#include "../include/valid_value.h"

int valid_int(char *val)
{
	while (*val >= '0' && *val <= '9')
		val++;
	return (!*val);
}

int valid_string(char* val)
{
	int	len;
	char*	spec = "\"";

	len = ft_strlen(val);
	if (*val != '\"' && val[len - 1] != '\"')
		return (0);
	val[len - 1] = 0;
	while (*(++val))
		if (instr(*val, spec) || (*val == '\\' && !instr(*(++val), spec)))
			return (0);
	return (1);
}

int valid_float(char* val)
{
	if (*val == '.')
		return (0);
	while (*val >= '0' && *val <= '9')
		val++;
	if (*val++ != '.')
		return (0);
	while (*val >= '0' && *val <= '9')
		val++;
	return (!*val);
}

int valid_boolean(char* val)
{
	return (!ft_strcmp(val, "true") || !ft_strcmp(val, "false"));
}

/*int main(int argc, char **argv)
{
	if (valid_boolean(argv[1]))
		printf("valid");
	else
		printf("invalid");
	printf("\n");
	return (0);
}*/