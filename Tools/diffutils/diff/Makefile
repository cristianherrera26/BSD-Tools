# $NetBSD: Makefile,v 1.1 2025/12/04 18:22:16 nia Exp $

PROG=	diff
SRCS=	diff.c diffdir.c diffreg.c xmalloc.c pr.c

CFLAGS+=-I../../../Headers
LDADD+=-L../../../Library/LibUser -luser

DPADD+=	${LIBM}
LDADD+=	-lm

WARNS=	3

.include <bsd.prog.mk>
