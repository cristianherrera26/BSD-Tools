#ifndef _COREUTILS_H
#define _COREUTILS_H	1

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "info.h"

#define PROJECT_NAME	"BSD miscutils"
#define PROJECT_VERSION	"11.99.6"

static void
show_version(void)
{
	printf("%s (%s) %s\n", __progname, PROJECT_NAME, PROJECT_VERSION);
	exit(0);
}

#define HOPT	1000
#define VOPT	1001

static const struct option def_longopts[] = {
	{ "help", no_argument, 0, HOPT},
	{ "version", no_argument, 0, VOPT},
	{0, 0, 0, 0}
};

#endif
