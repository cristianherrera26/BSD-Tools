PROG=	tail
SRCS=	forward.c misc.c read.c reverse.c tail.c
SYMLINKS=	${BINDIR}/tail ${BINDIR}/tac
MAN=	tail.1 tac.1

CFLAGS+=-I../../../Headers
LDADD+=-L../../../Library/LibUser -luser

.include <bsd.prog.mk>
