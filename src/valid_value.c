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
	if (*val++ != '.') return (0);
	while (*val >= '0' && *val <= '9')
		val++;
	return (!*val && *(val - 1) != '.');
}

int valid_boolean(char* val)
{
	return (!ft_strcmp(val, "true") || !ft_strcmp(val, "false"));
}

int	valid_operation(list* opr)
{
	int	paranthese;
	int	operator;
	char*	valid_opr = "+-*/";

	paranthese = 0;
	operator=  0;
	if (instr(*(char*)opr->value, valid_opr))
		return (0);
	while(opr)
	{
		if (!ft_strcmp((char*)opr->value, "("))
			paranthese++;
		else if (!ft_strcmp((char*)opr->value, ")") && paranthese)
			paranthese--;
		else if (!ft_strcmp((char*)opr->value, ")"))
			return (0);
		else if (operator)
			if (!valid_int((char*)opr->value))
				return (0);
		else
			if (!instr(*(char*)opr->value, valid_opr))
				return (0);
		operator = !operator;
		opr = opr->next;
	}
	return (!paranthese && !operator);
}