#ifndef _COREUTILS_H
#define _COREUTILS_H	1

#include <stdio.h>
#include <stdlib.h>
#include "info.h"

#define PROJECT_NAME	"BSD coreutils"
#define PROJECT_VERSION	"11.99.6"

static void
show_version(void)
{
	printf("%s (%s) %s\n", __progname, PROJECT_NAME, PROJECT_VERSION);
#if defined(_FALSE)
	exit(1);
#else
	exit(0);
#endif
}

#define HOPT	1000
#define VOPT	1001

#endif
