#ifndef _NB_GRP_H
#define _NB_GRP_H	1

#include_next <grp.h>

const char *group_from_gid(gid_t gid, int nogroup);
int gid_from_group(const char *name, gid_t *gid);

#endif
