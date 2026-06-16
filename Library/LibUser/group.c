#include <grp.h>
#include <err.h>
#include <stdio.h>
#include <string.h>

static gid_t group_from_gid_bef_gid;
static char group_from_gid_bef_groupname[128];

const char
*group_from_gid(gid_t gid, int nogroup)
{
	if (group_from_gid_bef_gid == gid)
		return group_from_gid_bef_groupname;
	
	struct group *gr = getgrgid(gid);
	if (!gr)
		err(1, "getgrgid");
	snprintf(group_from_gid_bef_groupname, sizeof(group_from_gid_bef_groupname), "%s", gr->gr_name);
	group_from_gid_bef_gid = gid;

	if (nogroup && group_from_gid_bef_groupname[0] == '\0')
		return NULL;

	if (!nogroup && group_from_gid_bef_groupname[0] != '\0')
		snprintf(group_from_gid_bef_groupname, sizeof(group_from_gid_bef_groupname), "%u", gid);

	return group_from_gid_bef_groupname;
}

static char gid_from_group_bef_groupname[128];
static gid_t gid_from_group_bef_gid;

int
gid_from_group(const char *name, gid_t *gid)
{
	if (!strcmp(name, gid_from_group_bef_groupname))	{
		*gid = group_from_gid_bef_gid;
		return 0;
	}

	struct group *gr = getgrnam(name);
	if (!gr)
		return 1;
	*gid = gr->gr_gid;
	gid_from_group_bef_gid = *gid;
	snprintf(gid_from_group_bef_groupname, sizeof(gid_from_group_bef_groupname), "%s", name);
	return 0;	
	
}
