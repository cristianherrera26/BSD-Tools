#include <sys/param.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <err.h>

static void usage(void);

int
main(int argc, char *argv[])
{
	int c, kflag = 0;
	setprogname(argv[0]);
	while ((c = getopt(argc, argv, "k")) != -1) {
		switch (c) {
		case 'k':
			kflag = 1;
			break;
		default:
			usage();
			break;
		}
	}

	argc -= optind;
	argv += optind;

	if (argc > 1)
		usage();

	if (argc == 1)
		return (!strcmp(argv[0], (kflag) ? MACHINE : MACHINE_ARCH)) ? 0 : 1;
	else 
		puts((kflag) ? MACHINE : MACHINE_ARCH);
	return 0;
}

static void
usage(void)
{
	fprintf(stderr, "usage: %s [-k] [archname]\n", getprogname());
	exit(0);
}
