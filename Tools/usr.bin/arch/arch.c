#include <sys/utsname.h>
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

	struct utsname uts;
	if (uname(&uts) != 0)
		err(1, "uname");

	puts(uts.machine);
	return 0;
}

static void
usage(void)
{

	fprintf(stderr, "usage: %s\n", getprogname());
	exit(1);
}
