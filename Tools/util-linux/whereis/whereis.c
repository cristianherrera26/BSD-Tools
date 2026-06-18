/*	$NetBSD: whereis.c,v 1.22 2025/06/01 15:45:31 jschauma Exp $	*/

/*-
 * Copyright (c) 1993
 *	The Regents of the University of California.  All rights reserved.
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
#include <sys/stat.h>

#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DEF_PATH	"/usr/bin:/usr/sbin:/bin:/sbin"
static void usage(void) __attribute__((noreturn));

int
main(int argc, char *argv[])
{
	struct stat sb;
	size_t len;
	int ch;
	char *p, std[MAXPATHLEN], path[MAXPATHLEN];
	const char *t;
	int which = strcmp(getprogname(), "which") == 0;
	int useenvpath = which, found = 0;
	gid_t egid = getegid();
	uid_t euid = geteuid();

	/* To make access(2) do what we want */
	if (setregid(egid, egid) == -1)
		err(1, "Can't set gid to %lu", (unsigned long)egid);
	if (setreuid(euid, euid) == -1)
		err(1, "Can't set uid to %lu", (unsigned long)euid);

	while ((ch = getopt(argc, argv, "ap")) != -1)
		switch (ch) {
		case 'a':
			which = 0;
			break;
		case 'p':
			useenvpath = 1;	/* use environment for PATH */
			break;

		case '?':
		default:
			usage();
		}
	argc -= optind;
	argv += optind;

	if (argc == 0)
		usage();

 	if (useenvpath) {
		char *tmp;
 		if ((tmp = getenv("PATH")) == NULL)
 			errx(1, "PATH environment variable is not set");
		snprintf(std, sizeof(std), "%s", tmp);
	} else {
		/* Retrieve the standard path. */
		snprintf(std, sizeof(std), "%s", DEF_PATH);
	}

	/* For each path, for each program... */
	for (; *argv; ++argv) {
		if (**argv == '/') {
			if (stat(*argv, &sb) == -1)
				continue; /* next argv */
			if (!S_ISREG(sb.st_mode))
				continue; /* next argv */
			if (access(*argv, X_OK) == -1)
				continue; /* next argv */
			(void)printf("%s\n", *argv);
			found++;
			if (which)
				continue; /* next argv */
		} else for (p = std; p; ) {
			t = p;
			if ((p = strchr(p, ':')) != NULL) {
				*p = '\0';
				if (t == p)
					t = ".";
			} else
				if (strlen(t) == 0)
					t = ".";
			(void)snprintf(path, sizeof(path), "%s/%s", t, *argv);
			len = snprintf(path, sizeof(path), "%s/%s", t, *argv);
			if (p)
				*p++ = ':';
			if (len >= sizeof(path))
				continue; /* next p */
			if (stat(path, &sb) == -1)
				continue; /* next p */
			if (!S_ISREG(sb.st_mode))
				continue; /* next p */
			if (access(path, X_OK) == -1)
				continue; /* next p */
			(void)printf("%s\n", path);
			found++;
			if (which)
				break; /* next argv */
		}
	}
	
	return ((found == 0) ? 3 : ((found >= argc) ? 0 : 2));
}

static void
usage(void)
{

	(void)fprintf(stderr, "Usage: %s [-ap] program [...]\n", getprogname());
	exit(1);
}
