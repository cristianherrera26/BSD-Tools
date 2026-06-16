#ifndef _NB_SYS_CDEFS_H
#define _NB_SYS_CDEFS_H	1

#include_next <sys/cdefs.h>

#define __UNCONST(a)	((void *)(unsigned long)(const void *)(a))
#define __printflike(a, b)
#define	MIN(a,b)	((/*CONSTCOND*/(a)<(b))?(a):(b))
#define __predict_false(exp)			__builtin_expect((exp) ? 1 : 0, 0)

#endif
