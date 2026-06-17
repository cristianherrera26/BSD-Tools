#	$NetBSD: Makefile,v 1.15 2020/12/25 07:00:52 dholland Exp $
#	@(#)Makefile	8.1 (Berkeley) 6/6/93

.include <bsd.own.mk>

CALENDARS=	birthday christian computer history holiday judaic \
		lotr music netbsd usholiday

PROG=	calendar

CFLAGS+=-I../../../Headers
LDADD+=-L../../../Library/LibUser -luser

FILESDIR=/usr/share/calendar
.for _C_ in ${CALENDARS}
FILES+=${.CURDIR}/calendars/calendar.${_C_}
.endfor

.include <bsd.prog.mk>
