#include <unistd.h>
#include <err.h>

int
fchroot(int fd)
{
	if (fchdir(fd) != 0)
		return -1;
	if (chroot(".") != 0)
		return -1;
	return 0;
}
