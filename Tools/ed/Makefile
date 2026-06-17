#	$NetBSD: Makefile,v 1.37 2017/05/21 15:28:36 riastradh Exp $

PROG=	ed
SRCS=	buf.c cbc.c glbl.c io.c main.c re.c sub.c undo.c

CFLAGS+=-I../../../../Headers
LDADD+=-L../../../../Library/LibUser -luser

.include <bsd.prog.mk>
