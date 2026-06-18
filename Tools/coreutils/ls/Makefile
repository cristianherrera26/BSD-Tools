PROG=	ls
SRCS=	cmp.c ls.c main.c print.c util.c

SYMLINKS=	${BINDIR}/ls ${BINDIR}/dir
SYMLINKS+=	${BINDIR}/ls ${BINDIR}/vdir
MLINKS=	ls.1	dir.1 \
	ls.1	vdir.1

CFLAGS+=-I../../../Headers
LDADD+=-L../../../Library/LibUser -luser

.include <bsd.prog.mk>
