#ifndef _COREUTILS_H
#define _COREUTILS_H	1

#include <stdio.h>
#include <stdlib.h>

#define BSD_NAME	"NetBSD"
#define BSD_VERSION	"11.99.6"
#define PROJECT_NAME	"BSD coreutils"
#define PROJECT_VERSION	BSD_VERSION // only for the first release

static void __attribute__((noreturn)) __attribute__((unused))
show_version(void)
{
	printf("%s (%s) %s\n", __progname, PROJECT_NAME, PROJECT_VERSION);
#if defined(_FALSE)
	exit(1);
#else
	exit(0);
#endif
}

extern void usage();

#define HOPT	1000
#define VOPT	1001

#endif
