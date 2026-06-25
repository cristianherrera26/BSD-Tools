#ifndef _NB_SYS_STAT_H
#define _NB_SYS_STAT_H	1

#include_next <sys/stat.h>
#include <sys/statvfs.h>
#include <stdbool.h>
#include <stdint.h>

#ifndef ALLPERMS
#define ALLPERMS (S_ISUID|S_ISGID|S_ISVTX|S_IRWXU|S_IRWXG|S_IRWXO)
#endif

#ifndef DEFFILEMODE
#define DEFFILEMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
#endif

#ifndef S_BLKSIZE
#define S_BLKSIZE	512
#endif

struct mntinfo {
    char *f_mntfromname;          /* mnt_fsname from getmntent */
    char *f_mntonname;            /* mnt_dir from getmntent */
    char *f_fstypename;           /* mnt_fsname from getmntent */
    char *f_opts;                 /* mnt_opts from getmntent */
    unsigned long f_bsize;        /* f_bsize from statvfs */
    fsblkcnt_t f_blocks;          /* f_blocks from statvfs */
    fsblkcnt_t f_bfree;           /* f_bfree from statvfs */
    fsblkcnt_t f_bavail;          /* f_bavail from statvfs */
    fsfilcnt_t f_files;           /* f_files from statvfs */
    fsfilcnt_t f_ffree;           /* f_ffree from statvfs */
    unsigned long f_flag;         /* f_flag from statvfs */
    dev_t f_dev;                  /* st_dev from stat */
    unsigned int f_selected;      /* used internally here only */
    uid_t f_owner;
    uint64_t f_syncwrites;
    uint64_t f_asyncwrites;
    unsigned long f_fsid;
};

int	  getmntinfo(struct mntinfo **, bool hide);
void	  freemntinfo(struct mntinfo *, int);

#endif
