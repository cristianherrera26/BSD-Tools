#ifndef _NB_STDIO_H
#define _NB_STDIO_H	1

#include_next <stdio.h>
#include <wchar.h>

char *fgetln(FILE *stream, size_t *len);
char *fparseln(FILE *fp, size_t *size, size_t *lineno, const char str[3], int flags);
wchar_t *fgetwln(FILE *stream, size_t *lenp);

#define FPARSELN_UNESCESC	0x01
#define FPARSELN_UNESCCONT	0x02
#define FPARSELN_UNESCCOMM	0x04
#define FPARSELN_UNESCREST	0x08
#define FPARSELN_UNESCALL	0x0f

#endif
