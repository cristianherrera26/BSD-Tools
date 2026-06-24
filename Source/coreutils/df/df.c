/*	$NetBSD: df.c,v 1.107 2026/04/08 00:58:36 kim Exp $ */

/*
 * Copyright (c) 1980, 1990, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 * (c) UNIX System Laboratories, Inc.
 * All or some portions of this file are derived from material licensed
 * to the University of California by American Telephone and Telegraph
 * Co. or Unix System Laboratories, Inc. and are reproduced herein with
 * the permission of UNIX System Laboratories, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/param.h>
#include <sys/statvfs.h>
#include <sys/stat.h>
#include <sys/mount.h>

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stdbool.h>
#include <fcntl.h>
#include <locale.h>
#include <util.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h>
#include <util.h>

static char	*getmntpt(struct mntinfo **, const size_t, const char *);
static void	 addstat(struct mntinfo *, struct mntinfo *);
static void	 prtstat(struct mntinfo *, int);
static void	 maketypelist(char *);
static void	 usage(void);
static void	 prthumanval(bool, int64_t, int);
static void	 prthuman(struct mntinfo *, int64_t, int64_t);

static int	 aflag, cflag, fflag, gflag, hflag, iflag, lflag;
static int	 Mflag, Nflag, nflag, Pflag, qflag, Wflag;
static long	 usize;
static char	**typelist;
static size_t	 mntcount;

#define WIDTH_BLKSIZE	12
#define WIDTH_INODE	10
static int blksize_width = WIDTH_BLKSIZE, inode_width = WIDTH_INODE;

static int fudgeunits = 0;

#define	streq(a, b)	(strcmp((a), (b)) == 0)
#define	warnq(args)	do { if (!qflag) warnx args; } while (0)

int
main(int argc, char *argv[])
{
	struct stat stbuf;
	struct mntinfo *mntbuf, totals;
	int ch, maxwidth, width;
	size_t i;
	char *mntpt;

	setprogname(argv[0]);
	(void)setlocale(LC_ALL, "");

	(void)strpct_round(STRPCT_RAZ);	/* POSIX: %'s round away from zero */

	while ((ch = getopt(argc, argv, "abcfGgHhiklMmNnPqt:W")) != -1)
		switch (ch) {
		case 'a':
			aflag = 1;
			break;
		case 'b':
			hflag = 0;
			usize = 512;
			break;
		case 'c':
			cflag = 1;
			break;
		case 'f':
			fflag = 1;
			break;
		case 'g':
			hflag = 0;
			usize = 1024 * 1024 * 1024;
			break;
		case 'G':
			gflag = 1;
			break;
		case 'H':
			fudgeunits = HN_DIVISOR_1000;
			/* FALL THROUGH */
		case 'h':
			hflag = 1;
			usize = 0;
			break;
		case 'i':
			iflag = 1;
			break;
		case 'k':
			hflag = 0;
			usize = 1024;
			break;
		case 'l':
			lflag = 1;
			break;
		case 'M':
			Mflag = 1;
			break;
		case 'm':
			hflag = 0;
			usize = 1024 * 1024;
			break;
		case 'N':
			Nflag = 1;
			break;
		case 'n':
			nflag = 1;
			break;
		case 'P':
			Pflag = 1;
			break;
		case 'q':
			qflag = 1;
			break;
		case 'W':
			Wflag = 1;
			break;
		case 't':
			if (typelist != NULL)
				errx(EXIT_FAILURE,
				    "only one -t option may be specified.");
			maketypelist(optarg);
			break;
		case '?':
		default:
			usage();
		}

	if (fflag && (Pflag || gflag))
		errx(EXIT_FAILURE,
		    "only one of -f -G and -P may be specified");
	if (gflag && (Pflag || iflag))
		errx(EXIT_FAILURE,
		    "only one of -G and -P or -i may be specified");
	if (Pflag && iflag)
		errx(EXIT_FAILURE,
		    "only one of -P and -i may be specified");
	if (fflag)
		Nflag = 1;

	argc -= optind;
	argv += optind;

	mntcount = getmntinfo(&mntbuf, true);
	if (mntcount == 0)
		err(EXIT_FAILURE, "retrieving information on mounted file systems");


	if (*argv) {
		for (int i = 0; i < mntcount; i++)
			mntbuf[i].f_selected = 0;
	}

	if (*argv == NULL) {
		mntcount = getmntinfo(&mntbuf, true);
	} else {
		for (/*EMPTY*/; *argv != NULL; argv++) {
			if (stat(*argv, &stbuf) < 0) {
				if ((mntpt = getmntpt(&mntbuf, mntcount, *argv)) == NULL) {
					if (!qflag)
						warn("%s", *argv);
					continue;
				}
			} else if (S_ISCHR(stbuf.st_mode)) {
				mntpt = getmntpt(&mntbuf, mntcount, *argv);
				if (!mntpt && !qflag)
					warn("%s: not mounted", *argv);
				continue;
			} else
				mntpt = *argv;

			for (int i = 0; i < mntcount; i++) {
				if (((stbuf.st_dev == mntbuf[i].f_dev) || !strcmp(mntbuf[i].f_mntfromname, mntpt) || !strcmp(mntbuf[i].f_mntonname, mntpt))) {
					mntbuf[i].f_selected = 1;
					break;
				}
			}
		}
	}

	if (cflag) {
		memset(&totals, 0, sizeof(totals));
		totals.f_bsize = DEV_BSIZE;
		strlcpy(totals.f_mntfromname, "total",
			sizeof(totals.f_mntfromname));
	}

	maxwidth = 0;
	for (i = 0; i < mntcount; i++) {
		width = 0;
		if (width == 0)
			width = (int)strlen(mntbuf[i].f_mntfromname);
		if (width > maxwidth)
			maxwidth = width;
		if (cflag)
			addstat(&totals, &mntbuf[i]);
	}

	for (int i = 0; i < mntcount; i++) {
		if (!mntbuf[i].f_selected)
			continue;
		if (!aflag && mntbuf[i].f_blocks <= 0)
			continue;

		prtstat(&mntbuf[i], maxwidth);
	}

	if (cflag)
		prtstat(&totals, maxwidth);

	return 0;
}

static char *
getmntpt(struct mntinfo **mntbuf, const size_t mntsize, const char *name)
{
	size_t i;

	if (mntsize == 0 || mntbuf == NULL || name == NULL)
		return NULL;

	for (i = 0; i < mntsize; i++) {
		if (mntbuf[i] == NULL)
			continue;;
	}

	return (NULL);
}

static enum { IN_LIST, NOT_IN_LIST } which;

static void
maketypelist(char *fslist)
{
	size_t i;
	char *nextcp, **av;

	if ((fslist == NULL) || (fslist[0] == '\0'))
		errx(EXIT_FAILURE, "empty type list");

	/*
	 * XXX
	 * Note: the syntax is "noxxx,yyy" for no xxx's and
	 * no yyy's, not the more intuitive "noyyy,noyyy".
	 */
	if (fslist[0] == 'n' && fslist[1] == 'o') {
		fslist += 2;
		which = NOT_IN_LIST;
	} else
		which = IN_LIST;

	/* Count the number of types. */
	for (i = 1, nextcp = fslist;
	    (nextcp = strchr(nextcp, ',')) != NULL; i++)
		++nextcp;

	/* Build an array of that many types. */
	if ((av = typelist = calloc((i + 1), sizeof(*av))) == NULL)
		err(EXIT_FAILURE, "can't allocate type array");
	av[0] = fslist;
	for (i = 1, nextcp = fslist;
	    (nextcp = strchr(nextcp, ',')) != NULL; i++) {
		*nextcp = '\0';
		av[i] = ++nextcp;
	}
	/* Terminate the array. */
	av[i] = NULL;
}

static void
prthumanval(bool bytes, int64_t value, int width)
{
	char buf[6];

	(void)humanize_number(buf, sizeof(buf) - (value < 0 ? 0 : 1),
	    value, "", HN_AUTOSCALE,
	    (bytes ? HN_B : HN_DIVISOR_1000) |
	    HN_NOSPACE | HN_DECIMAL | fudgeunits);

	(void)printf("%*s", width, buf);
}

static void
prthuman(struct mntinfo *sfsp, int64_t used, int64_t bavail)
{

	prthumanval(true,
	    (int64_t)(sfsp->f_blocks * sfsp->f_bsize),
	    blksize_width);
	prthumanval(true,
	    (int64_t)(used * sfsp->f_bsize),
	    1 + blksize_width);
	prthumanval(true,
	    (int64_t)(bavail * sfsp->f_bsize),
	    1 + blksize_width);
}

/*
 * Convert statvfs returned filesystem size into BLOCKSIZE units.
 * Attempts to avoid overflow for large filesystems.
 */
#define fsbtoblk(num, fsbs, bs)					\
	(((fsbs) != 0 && (uint64_t)(fsbs) < (uint64_t)(bs)) ?	\
	    (int64_t)(num) / (int64_t)((bs) / (fsbs)) :		\
	    (int64_t)(num) * (int64_t)((fsbs) / (bs)))

static void
addstat(struct mntinfo *totalfsp, struct mntinfo *sfsp)
{
	uint64_t bsize;

	bsize = sfsp->f_bsize / totalfsp->f_bsize;
	totalfsp->f_blocks += sfsp->f_blocks * bsize;
	totalfsp->f_bfree += sfsp->f_bfree * bsize;
	totalfsp->f_bavail += sfsp->f_bavail * bsize;
	totalfsp->f_files += sfsp->f_files;
	totalfsp->f_ffree += sfsp->f_ffree;
}

/*
 * Print out status about a filesystem.
 */
static void
prtstat(struct mntinfo *sfsp, int maxwidth)
{
	static long blocksize;
	static int headerlen, timesthrough;
	static const char *header;
	static const char full[] = "100";
	static const char empty[] = "  0";
	struct statvfs *statvfs_sfsp = NULL;
	int64_t used, availblks, inodes;
	int64_t bavail;
	char pb[64];
	char mntfromname[sizeof(sfsp->f_mntfromname) + 10];

	strlcpy(mntfromname, sfsp->f_mntfromname, sizeof(mntfromname));

	if (gflag) {
		/*
		 * From SunOS-5.6:
		 *
		 * /var               (/dev/dsk/c0t0d0s3 ):         8192 block size          1024 frag size
		 *   984242 total blocks     860692 free blocks   859708 available         249984 total files
		 *   248691 free files      8388611 filesys id
		 *      ufs fstype       0x00000004 flag             255 filename length
		 *
		 */
		(void)printf("%10s (%-12s): %7ld block size %12ld frag size\n",
		    sfsp->f_mntonname, mntfromname,
		    sfsp->f_bsize,	/* On UFS/FFS systems this is
					 * also called the "optimal
					 * transfer block size" but it
					 * is of course the file
					 * system's block size too.
					 */
		    sfsp->f_bsize);	/* not so surprisingly the
					 * "fundamental file system
					 * block size" is the frag
					 * size.
					 */
		(void)printf("%10" PRId64 " total blocks %10" PRId64
		    " free blocks  %10" PRId64 " available\n",
		    (uint64_t)sfsp->f_blocks, (uint64_t)sfsp->f_bfree,
		    (uint64_t)sfsp->f_bavail);
		(void)printf("%10" PRId64 " total files  %10" PRId64
		    " free files %12lx filesys id\n",
		    (uint64_t)sfsp->f_files, (uint64_t)sfsp->f_ffree,
		    sfsp->f_fsid);
		(void)printf("%10s fstype  %#15lx flag  %17ld filename "
		    "length\n", sfsp->f_fstypename, sfsp->f_flag,
		    statvfs_sfsp->f_namemax);
		(void)printf("%10lu owner %17" PRId64 " syncwrites %12" PRId64
		    " asyncwrites\n\n", (unsigned long)sfsp->f_owner,
		    sfsp->f_syncwrites, sfsp->f_asyncwrites);
		/*
		 * a concession by the structured programming police to the
		 * indentation police....
		 */
		return;
	}
	if (maxwidth < 12)
		maxwidth = 12;
	if (++timesthrough == 1) {
		switch (blocksize = usize) {
		case 512:
			header = "512-blocks";
			headerlen = (int)strlen(header);
			break;
		case 1024:
			header = Pflag ? "1024-blocks" : "1K-blocks";
			headerlen = (int)strlen(header);
			break;
		case 1024 * 1024:
			header = "1M-blocks";
			headerlen = (int)strlen(header);
			break;
		case 1024 * 1024 * 1024:
			header = "1G-blocks";
			headerlen = (int)strlen(header);
			break;
		default:
			if (hflag) {
				header = "Size";
				headerlen = (int)strlen(header);
				blksize_width = inode_width = 6;
			} else
				header = getbsize(&headerlen, &blocksize);
			break;
		}

		if (blocksize >= 1024 * 1024)
			blksize_width -= 3;
		if (blocksize >= 1024 * 1024 * 1024)
			blksize_width -= 3;
		if (blksize_width < headerlen)
			blksize_width = headerlen;

		if (Pflag) {
			/*
			 * either:
			 *  "Filesystem 1024-blocks Used Available Capacity Mounted on\n"
			 * or:
			 *  "Filesystem 512-blocks Used Available Capacity Mounted on\n"
			 */
			if (blocksize != 1024 && blocksize != 512)
				errx(EXIT_FAILURE,
				    "non-standard block size incompatible with -P");
			(void)printf("Filesystem %s Used Available Capacity "
			    "Mounted on\n", header);
		} else if (!Nflag) {
			(void)printf("%-*.*s %*s %*s %*s %%Cap",
			    maxwidth, maxwidth, "Filesystem",
			    blksize_width, header,
			    blksize_width, "Used",
			    blksize_width, "Avail");
			if (iflag) {
				(void)printf(" %*s %*s %%iCap",
				    inode_width, "iUsed",
				    inode_width, "iAvail");
			}
			(void)printf(" Mounted on\n");
		}
	}
	used = sfsp->f_blocks - sfsp->f_bfree;
	bavail = sfsp->f_bavail;
	availblks = bavail + used;
	if (Pflag) {
		assert(hflag == 0);
		assert(blocksize > 0);
		/*
		 * "%s %d %d %d %s %s\n", <file system name>, <total space>,
		 * <space used>, <space free>, <percentage used>,
		 * <file system root>
		 */
		(void)printf("%s %" PRId64 " %" PRId64 " %" PRId64 " %s%% %s\n",
		    mntfromname,
		    fsbtoblk(sfsp->f_blocks, sfsp->f_bsize, blocksize),
		    fsbtoblk(used, sfsp->f_bsize, blocksize),
		    fsbtoblk(bavail, sfsp->f_bsize, blocksize),
		    availblks == 0 ? full : strspct(pb, sizeof(pb), used,
		    availblks, 0), sfsp->f_mntonname);
		/*
		 * another concession by the structured programming police to
		 * the indentation police....
		 *
		 * Note iflag cannot be set when Pflag is set.
		 */
		return;
	}

	if (fflag) {
		if (iflag)
			(void)printf("%jd", sfsp->f_ffree);
		else if (hflag)
			prthumanval(true, bavail * sfsp->f_bsize, 1);
		else
			(void)printf("%jd", fsbtoblk(bavail,
			    sfsp->f_bsize, blocksize));

		if (mntcount != 1)
			(void)printf(" %s\n", sfsp->f_mntonname);
		else
			(void)printf("\n");
		return;
	}

	(void)printf("%-*.*s ", maxwidth, maxwidth, mntfromname);

	if (hflag)
		prthuman(sfsp, used, bavail);
	else
		(void)printf("%*" PRId64 " %*" PRId64 " %*" PRId64,
		    blksize_width,
		    fsbtoblk(sfsp->f_blocks, sfsp->f_bsize, blocksize),
		    blksize_width, fsbtoblk(used, sfsp->f_bsize, blocksize),
		    blksize_width, fsbtoblk(bavail, sfsp->f_bsize, blocksize));
	(void)printf(" %3s%%",
	    availblks == 0 ? full :
	    strspct(pb, sizeof(pb), used, availblks, 0));
	if (iflag) {
		inodes = sfsp->f_files;
		used = inodes - sfsp->f_ffree;
		if (hflag) {
			prthumanval(false,
			    (int64_t)used,
			    1 + inode_width);
			prthumanval(false,
			    (int64_t)sfsp->f_ffree,
			    1 + inode_width);
		} else
			(void)printf(" %*jd %*jd",
			    inode_width, (intmax_t)used,
			    inode_width, (intmax_t)sfsp->f_ffree);
		(void)printf(" %4s%%",
		    inodes == 0 ? (used == 0 ? empty : full) :
		    strspct(pb, sizeof(pb), used, inodes, 0));
	}
	(void)printf(" %s\n", sfsp->f_mntonname);
}

static void
usage(void)
{

	(void)fprintf(stderr,
	    "Usage: %s [-aclMnqW] [-G|-bkP|-bfgHhikmN] [-t type] [file | "
	    "file_system]...\n",
	    getprogname());
	exit(1);
	/* NOTREACHED */
}
