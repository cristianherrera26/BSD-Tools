#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <err.h>
#include "coreutils.h"

static void usage();

static const struct option longopts[] = {
	{ "help", no_argument, 0, HOPT},
	{ "version", no_argument, 0, VOPT},
	{0, 0, 0, 0}
};

int
main(int argc, char *argv[])
{
	int c;
	setprogname(argv[0]);
	while ((c = getopt_long(argc, argv, "", longopts, NULL)) != -1) {
		switch (c) {
			case HOPT:
				usage();
				break;
			case VOPT:
				show_version();
				break;
			default:
				fprintf(stderr, "Try '%s --help' for more information.\n", getprogname());
				break;
		}
	}

	argc -= optind;
	argv += optind;

	if (argc != 0) {
		fprintf(stderr, "%s: extra operand '%s'\n", getprogname(), argv[0]);
		fprintf(stderr, "Try '%s --help' fore more information\n", getprogname());
		return 1;
	}

	printf("%08lx\n", gethostid() & 0xFFFFFFFF);
	return 0;
}

static void
usage(void)
{
	printf("Usage: %s\n"
		"Description: Print the numeric indentifier for the current host.\n"
		"\nGeneral Options:\n"
		"      --help           Print help information\n"
		"      --version        Print version\n",
		getprogname());
	exit(0);
}
