#include <grp.h>
#include <err.h>
#include <stdio.h>
#include <string.h>

const char
*group_from_gid(gid_t gid, int nogroup)
{	
	char *buf = NULL;
	struct group *gr = getgrgid(gid);
	if (!gr)
		err(1, "getgrgid");

	if (nogroup && !gr->gr_name)
		return NULL;

	if (!nogroup && !gr->gr_name) {
		snprintf(buf, sizeof(buf), "%u", gid);
		return buf;
	}

	return gr->gr_name;
}

int
gid_from_group(const char *name, gid_t *gid)
{
	struct group *gr = getgrnam(name);
	if (!gr)
		return 1;
	*gid = gr->gr_gid;
	return 0;	
	
}
