#	$NetBSD: Makefile,v 1.20 2019/10/04 08:57:37 mrg Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

PROG=dd
SRCS=	args.c conv.c dd.c dd_swab.c misc.c position.c dd_hostops.c

CPPFLAGS+=	-DNO_CONV -DNO_MSGFMT -DNO_IOFLAG -DSMALL

CFLAGS+=-I../../../Headers
LDADD+=-L../../../Library/LibUser -luser

.include <bsd.prog.mk>
