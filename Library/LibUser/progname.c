#include <string.h>

const char *__progname;

void
setprogname(const char *progname)
{
	__progname = strrchr(progname, '/');
	if (!__progname)
		__progname = progname;
	else
		__progname++;
}

const char
*getprogname(void)
{
	return __progname;
}
