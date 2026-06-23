#include <sys/param.h>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>

static void usage(void);

int
main(int argc, char *argv[])
{
	int c;
	struct utsname uts;
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

	if (uname(&uts) != 0)
		err(1, "uname");

	puts(uts.machine);
	return 0;
}

static void
usage(void)
{
	fprintf(stderr, "usage: %s\n", getprogname());
	exit(0);
}
