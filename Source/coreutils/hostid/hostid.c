#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <err.h>

static void usage();

int
main(int argc, char *argv[])
{
	int c;
	setprogname(argv[0]);
	while ((c = getopt(argc, argv, "")) != -1) {
		switch (c) {
			default:
				usage();
				break;
		}
	}

	argc -= optind;
	argv += optind;

	if (argc != 0)
		usage();

	printf("%08lx\n", gethostid() & 0xFFFFFFFF);
	return 0;
}

static void
usage(void)
{
	fprintf(stderr, "usage: %s\n", getprogname());
	exit(1);
}
