#ifndef _NB_STDLIB_H
#define _NB_STDLIB_H	1

#include_next <stdlib.h>
#include <stdint.h>

extern const char *__progname;
const char *getprogname(void);
void setprogname(const char *progname);
int reallocarr(void *ptr, size_t number, size_t size);
char *getbsize(int *headerlenp, long *blocksizep);
int humanize_number(char *buf, size_t len, int64_t bytes, const char *suffix, int scale, int flags);
long long strsuftoll(const char *desc, const char *val, long long min, long long max);
long long strsuftollx(const char *desc, const char *val, long long min, long long max, char *ebuf, size_t ebuflen);
intmax_t strtoi(const char *__restrict nptr, char **__restrict endptr, int base, intmax_t lo, intmax_t hi, int *rstatus);

#define HN_DECIMAL              0x01
#define HN_NOSPACE              0x02
#define HN_B                    0x04
#define HN_DIVISOR_1000         0x08

#define HN_GETSCALE             0x10
#define HN_AUTOSCALE            0x20

#endif
