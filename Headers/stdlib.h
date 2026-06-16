#ifndef _NB_STDLIB_H
#define _NB_STDLIB_H	1

#include_next <stdlib.h>

extern const char *__progname;
const char *getprogname(void);
void setprogname(const char *progname);
int reallocarr(void *ptr, size_t number, size_t size);
char *getbsize(int *headerlenp, long *blocksizep);
int humanize_number(char *buf, size_t len, int64_t bytes, const char *suffix, int scale, int flags);

#define HN_DECIMAL              0x01
#define HN_NOSPACE              0x02
#define HN_B                    0x04
#define HN_DIVISOR_1000         0x08

#define HN_GETSCALE             0x10
#define HN_AUTOSCALE            0x20

#endif
