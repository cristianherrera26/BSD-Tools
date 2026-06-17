#	$NetBSD: Makefile,v 1.17 2025/10/19 00:59:59 riastradh Exp $
#	@(#)Makefile	8.1 (Berkeley) 5/31/93

.include <bsd.own.mk>

PRIMES=	../../miscutils/primes

PROG=	factor
SRCS=	factor.c pr_tbl.c
CPPFLAGS+=-I${PRIMES}

CPPFLAGS+=-DHAVE_OPENSSL
LDADD+=	-lcrypto -lcrypt
DPADD+=	${LIBCRYPTO} ${LIBCRYPT}

CFLAGS+=-I../../../Headers -Wno-deprecated-declarations
LDADD+=-L../../../Library/LibUser -luser

.PATH:${PRIMES}

.include <bsd.prog.mk>
