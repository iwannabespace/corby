#ifndef _colorizer_h_
#define _colorizer_h_

#include <stdio.h>

#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYNAN   "\x1B[36m"
#define WHITE   "\x1B[37m"

void set_text_color(const char* color);

#endif