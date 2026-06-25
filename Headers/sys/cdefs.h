#ifndef _NB_SYS_CDEFS_H
#define _NB_SYS_CDEFS_H	1

#include <features.h>
#ifdef __GLIBC__
#include_next <sys/cdefs.h>
#endif

#define __UNCONST(a)	((void *)(unsigned long)(const void *)(a))

#ifndef MIN
#define	MIN(a,b)	((/*CONSTCOND*/(a)<(b))?(a):(b))
#endif

#define __predict_false(exp)			__builtin_expect((exp) ? 1 : 0, 0)
#define	__USE(a) (/*LINTED*/(void)(a))

#endif
