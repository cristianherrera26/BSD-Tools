#ifndef _UTIL_H
#define _UTIL_H	1

#include <stdint.h>

/* Definitions for the strpct() functions rounding modes */
#define	STRPCT_RTN		0U	/* Round to nearest */
#define	STRPCT_RAZ		2U	/* Round away from zero */
#define	STRPCT_RTZ		3U	/* Round towards zero */
#define	STRPCT_RTI		6U	/* Round towards +Inf */
#define	STRPCT_RAI		7U	/* Round away from +Inf (to -Inf) */
/* Do not alter those 5 values, the implementation depends upon them */
#define	STRPCT_RQRY		8U	/* Any value not one of the above */

char 	       *strpct(char *, size_t, uintmax_t, uintmax_t, size_t);
char 	       *strspct(char *, size_t, intmax_t, intmax_t, size_t);
char 	       *strpct_r(char *, size_t, uintmax_t, uintmax_t, size_t, uint32_t);
char 	       *strspct_r(char *,size_t, intmax_t, intmax_t, size_t, uint32_t);
uint32_t	strpct_round(uint32_t);

char *flags_to_string(unsigned long flags, const char *def);

#endif
