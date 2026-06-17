PROG=	test
SRCS=   test.c
LINKS=	${BINDIR}/test ${BINDIR}/[
MLINKS=	test.1 [.1

CFLAGS+=-I../../../Headers
LDADD+=-L../../../Library/LibUser -luser

.include <bsd.prog.mk>
