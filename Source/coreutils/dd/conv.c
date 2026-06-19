/*	$NetBSD: conv.c,v 1.17 2003/08/07 09:05:10 agc Exp $	*/

/*-
 * Copyright (c) 1991, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Keith Muller of the University of California, San Diego and Lance
 * Visser of Convex Computer Corporation.
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
#include <sys/time.h>

#include <err.h>
#include <string.h>
#include <stdlib.h>

#include "dd.h"
#include "extern.h"

/*
 * def --
 * Copy input to output.  Input is buffered until reaches obs, and then
 * output until less than obs remains.  Only a single buffer is used.
 * Worst case buffer calculation is (ibs + obs - 1).
 */
void
def(void)
{
	uint64_t cnt;
	u_char *inp;
	const u_char *t;

	if ((t = ctab) != NULL)
		for (inp = in.dbp - (cnt = in.dbrcnt); cnt--; ++inp)
			*inp = t[*inp];

	/* Make the output buffer look right. */
	out.dbp = in.dbp;
	out.dbcnt = in.dbcnt;

	if (in.dbcnt >= out.dbsz) {
		/* If the output buffer is full, write it. */
		dd_out(0);

		/*
		 * Ddout copies the leftover output to the beginning of
		 * the buffer and resets the output buffer.  Reset the
		 * input buffer to match it.
	 	 */
		in.dbp = out.dbp;
		in.dbcnt = out.dbcnt;
	}
}

void
def_close(void)
{

	/* Just update the count, everything is already in the buffer. */
	if (in.dbcnt)
		out.dbcnt = in.dbcnt;
}

/* Build a smaller version (i.e. for a miniroot) */
/* These can not be called, but just in case...  */
static const char no_block[] = "unblock and -DNO_CONV?";
void block(void)		{ errx(EXIT_FAILURE, "%s", no_block + 2); }
void block_close(void)		{ errx(EXIT_FAILURE, "%s", no_block + 2); }
void unblock(void)		{ errx(EXIT_FAILURE, "%s", no_block); }
void unblock_close(void)	{ errx(EXIT_FAILURE, "%s", no_block); }
