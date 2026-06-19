#ifndef _SYS_ENDIAN_H
#define _SYS_ENDIAN_H	1

#include <stdint.h>

#define __CAST(__dt, __st)	((__dt)(__st))

static inline uint16_t
be16dec(const void *_buf)
{
	const uint8_t *p = __CAST(const uint8_t *, _buf);

	return ((__CAST(uint16_t, p[0]) << 8) | p[1]);
}


static inline uint32_t
be32dec(const void *_buf)
{
	const uint8_t *p = __CAST(const uint8_t *, _buf);

	return ((__CAST(uint32_t, be16dec(p)) << 16) | be16dec(p + 2));
}

#endif
