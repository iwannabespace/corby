#include <stdio.h>

#include "include/parser.h"
#include "include/compiler.h"

int	main(int argc, char **argv)
{
	int i = 1;
	
	for (; argv[i]; i++) {}

	printf("String count: %d\n", i - 1);
		

	return (0);
}