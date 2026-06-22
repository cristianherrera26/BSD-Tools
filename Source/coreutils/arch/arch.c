#include <sys/param.h>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>
#include "coreutils.h"

static void usage(void);

int
main(int argc, char *argv[])
{
	int c;
	struct utsname uts;
	setprogname(argv[0]);
	while ((c = getopt_long(argc, argv, "", def_longopts, NULL)) != -1) {
		switch (c) {
		case HOPT:
			usage();
			break;
		case VOPT:
			show_version();
			break;
		default:
			fprintf(stderr, "Try '%s --help' for more information.\n", getprogname());
			return 1;
			break;
		}
	}

	argc -= optind;
	argv += optind;

	if (argc != 0) {
		fprintf(stderr, "%s: extra operand '%s'\n", getprogname(), argv[0]);
		fprintf(stderr, "Try '%s --help' for more information.\n", getprogname());
		return 1;
	}

	if (uname(&uts) != 0)
		err(1, "uname");

	puts(uts.machine);
	return 0;
}

static void
usage(void)
{
	printf("Usage: %s\n"
		"Description: Print machine architecture\n"
		"\nGeneral Options:\n"
		"      --help           Print help information\n"
		"      --version        Print version\n", 
		getprogname());
	exit(0);
}
