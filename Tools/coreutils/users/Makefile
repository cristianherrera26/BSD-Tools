.include <bsd.own.mk>

PROG=	users
SRCS=	users.c utmpentry.c

.PATH.c: ../who

CFLAGS+=-I../../../Headers -I../who
LDADD+=-L../../../Library/LibUser -luser

.include <bsd.prog.mk>
