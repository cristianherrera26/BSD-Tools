#ifndef _NB_STRING_H
#define _NB_STRING_H	1

#include_next <string.h>
#include <stdbool.h>
#include <unistd.h>

void strmode(mode_t mode, char *p);
bool isin_array(char *find, char **where);

#endif
