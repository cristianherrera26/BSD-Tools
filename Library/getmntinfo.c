#include <sys/stat.h>
#include <sys/statvfs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mntent.h>
#include <assert.h>
#include <errno.h>
#include <err.h>

char *skipfs[] = {
	"proc", "sys", "securityfs", "devpts",
	"cgroup2", "bpf", "none", "systemd-1",
	"portal", "gvfsd-fuse", "configfs", "debugfs",
	"tracefs", "mqueue", "fusectl", "hugetlbfs", 
	"binfmt_misc", NULL
};

int
getmntinfo(struct mntinfo **mntbuf, bool hide)
{
	struct mntinfo *list = NULL;
	struct mntinfo *current = NULL;
	struct mntent *ent = NULL;
	int mntsize = 0;
	FILE *fp = NULL;
	struct statvfs svfsbuf;
	struct stat stmnt;

#ifdef _PATH_MOUNTED
	fp = setmntent(_PATH_MOUNTED, "r");
#else
	if (access("/proc/self/mounts", R_OK) == 0) {
	    fp = setmntent("/proc/self/mounts", "r");
	} else if (access("/proc/mounts", R_OK) == 0) {
	    fp = setmntent("/proc/mounts", "r");
	} else if (access("/etc/mtab", R_OK) == 0) {
	    fp = setmntent("/etc/mtab", "r");
	}
#endif

	if (fp == NULL)
	    err(1, "setmntent");

	while ((ent = getmntent(fp)) != NULL) {
	    if (hide && isin_array(ent->mnt_fsname, skipfs))
		continue;

	    /* get stat(vfs) fields and copy those over */
	    if (statvfs(ent->mnt_dir, &svfsbuf) == -1 || stat(ent->mnt_dir, &stmnt) == -1) {
	        if ((errno == EACCES) || (errno == EPERM) || (errno == ENOTCONN)) continue;
	        err(1, "statvfs");
	    }

	    /* allocate the entry */
	    list = realloc(list, (mntsize + 1) * sizeof(*list));
	    assert(list != NULL);
	    current = list + mntsize;

	    /* fill the struct with getmntent fields */
	    current->f_fstypename = strdup(ent->mnt_type);
	    current->f_mntfromname = strdup(ent->mnt_fsname);
	    current->f_mntonname = strdup(ent->mnt_dir);
	    current->f_opts = strdup(ent->mnt_opts);

	    current->f_flag = svfsbuf.f_flag;
	    current->f_blocks = svfsbuf.f_blocks;
	    current->f_bsize = svfsbuf.f_bsize;
	    current->f_bfree = svfsbuf.f_bfree;
	    current->f_bavail = svfsbuf.f_bavail;
	    current->f_files = svfsbuf.f_files;
	    current->f_ffree = svfsbuf.f_ffree;

	    current->f_dev = stmnt.st_dev;

	    current->f_selected = 1;

	    mntsize++;
	}

	endmntent(fp);

	*mntbuf = list;
	return mntsize;
}

void
freemntinfo(struct mntinfo *mntbuf, int mntsize)
{
	int i = 0;

	for (i = 0; i < mntsize; i++) {
	    free(mntbuf[i].f_fstypename);
	    free(mntbuf[i].f_mntfromname);
	    free(mntbuf[i].f_mntonname);
	    free(mntbuf[i].f_opts);
	}

	free(mntbuf);
}
