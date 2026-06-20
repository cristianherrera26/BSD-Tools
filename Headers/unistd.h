#ifndef _NB_UNISTD_H
#define _NB_UNISTD_H	1

#include_next <unistd.h>

#ifdef __GLIBC__
typedef __mode_t mode_t;
#endif

mode_t getmode(const void *bbox, mode_t omode);
void *setmode(const char *p);

int fchroot(int fd);

#endif
