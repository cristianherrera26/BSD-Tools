#	$NetBSD: Makefile,v 1.31 2023/07/20 16:21:23 lukem Exp $
#	@(#)Makefile	8.1 (Berkeley) 6/6/93

.include <bsd.own.mk>

PROG=	xinstall
SRCS=	xinstall.c getid.c
MAN=	install.1

SYMLINKS=${BINDIR}/xinstall ${BINDIR}/install

CFLAGS+=-I../../../Headers
LDADD+=-L../../../Library/LibUser -luser -lmd

.include <bsd.prog.mk>
