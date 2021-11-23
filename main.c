#include <stdio.h>

#include "include/parser.h"
#include "include/compiler.h"
#include "include/colorizer.h"

int main(int argc, char** argv)
{
    list* data = ft_parse("src/e.corby");
    c_result result = compile(data);

	for (; data; data = data->next)
	{
		CMD* line = data->value;
		list* tokens = line->value;

		for (; tokens; tokens = tokens->next)
			printf("%s ", (char*)tokens->value);
		
		printf("\n");
	}


    /*if (result.error_count == 0)
    {
        set_text_color(GREEN);

        if (result.warning_count == 0)
            printf("Compilation successfull!\n");

        else
        {
            if (result.warning_count > 1)
                printf("%d warnings are found\nCompilation successfull!\n", result.warning_count);

            else
                printf("%d warning is found\nCompilation successfull!\n", result.warning_count);
        }

        set_text_color(RESET);
    }

    else
    {
        set_text_color(MAGENTA);

        if (result.error_count > 1)
        {
            if (result.warning_count > 1)
                printf("%d errors and %d warnings are found\nCompilation failed!\n", result.error_count, result.warning_count);
            
            else
                printf("%d errors and %d warning are found\nCompilation failed!\n", result.error_count, result.warning_count);
        }

        else
        {
            if (result.warning_count > 1)
                printf("%d error and %d warnings are found\nCompilation failed!\n", result.error_count, result.warning_count);
            
            else
                printf("%d error and %d warning are found\nCompilation failed!\n", result.error_count, result.warning_count);
        }

        set_text_color(RESET);
    }*/

    return 0;
}