/*	$NetBSD: domainname.c,v 1.15 2011/08/29 14:51:18 joerg Exp $	*/

/*
 * Copyright (c) 1988, 1993
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

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "miscutils.h"

static void usage(void);

int
main(int argc, char *argv[])
{
	int c;
	char domainname[MAXHOSTNAMELEN];
	setprogname(argv[0]);
	while ((c = getopt_long(argc, argv, "", def_longopts, NULL)) != -1) {
		switch (c) {
		case HOPT:
			usage();
			break;
		case VOPT:
			show_version();
			break;
		default:
			fprintf(stderr, "Try '%s --help' for more information.\n", getprogname());
			return 1;
			break;
		}
	}
	argc -= optind;
	argv += optind;

	if (argc > 1) {
		fprintf(stderr, "%s: extra operand '%s'\n", getprogname(), argv[1]);
		fprintf(stderr, "Try '%s --help' for more information.\n", getprogname());
		return 1;
	}

	if (*argv) {
		if (setdomainname(*argv, strlen(*argv)))
			err(1, "setdomainname");
	} else {
		if (getdomainname(domainname, sizeof(domainname)))
			err(1, "getdomainname");
		printf("%s\n", domainname);
	}

	return 0;
}

static void
usage(void)
{
	printf("Usage: %s [NAME]\n"
		"Description: Set or print YP domain of current host system.\n"
		"\nGeneral Options:\n"
		"      --help           Print help information\n"
		"      --version        Print version\n",
		getprogname());
	exit(0);
}
