#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

__attribute__((noreturn)) static void usage();

int
main(int argc, char *argv[])
{
	int c;
	setprogname(argv[0]);
	long hostid;
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

	hostid = gethostid() & 0xFFFFFFFF;
	if (!hostid)
		err(1, "gethostid");
	printf("%08lx\n", hostid);
	return 0;
}

static void
usage(void)
{

	fprintf(stderr, "usage: %s\n", getprogname());
	exit(1);
}
