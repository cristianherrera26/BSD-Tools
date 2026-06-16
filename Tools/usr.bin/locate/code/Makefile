#	$NetBSD: Makefile,v 1.7 2002/09/18 14:00:39 lukem Exp $
#	@(#)Makefile	8.1 (Berkeley) 6/6/93

NOMAN=	# defined

PROG=	locate.code
CPPFLAGS+=-I${.CURDIR}/../locate
BINDIR=	/usr/libexec

CFLAGS+=-I../../../../Headers
LDADD+=-L../../../../Library/LibUser -luser

.include <bsd.prog.mk>
