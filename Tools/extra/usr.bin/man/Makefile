#	$NetBSD: Makefile,v 1.17 2023/06/03 09:09:17 lukem Exp $
#	@(#)Makefile	8.1 (Berkeley) 6/6/93

WARNS?=	6

PROG=	man
SRCS=	man.c manconf.c
MAN=	man.1 man.conf.5

COPTS.man.c+=	${CC_WNO_FORMAT_TRUNCATION}

CFLAGS+=-I../../../Headers
LDADD+=-L../../../Library/LibUser -luser

.include <bsd.prog.mk>
