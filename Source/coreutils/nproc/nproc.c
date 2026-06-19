#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

__attribute__((noreturn)) static void usage();

int
main(int argc, char *argv[])
{
	int c;
	long cores;
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

	if (argc)
		usage();

	cores = sysconf(_SC_NPROCESSORS_CONF);
	if (cores == -1)
		err(1, "uname");
	if (cores < 1)
		cores = 1;

	printf("%ld\n", cores);
	return 0;
}

static void
usage(void)
{

	fprintf(stderr, "usage: %s\n", getprogname());
	exit(1);
}
