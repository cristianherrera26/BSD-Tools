#ifndef _NB_SYS_PARAM_H
#define _NB_SYS_PARAM_H	1

#include_next <sys/param.h>

#if !defined(MACHINE_ARCH) && defined(__linux__)
 #if defined(__x86_64__)
 #define	MACHINE_ARCH	"x86_64"
 #elif defined(__i386__)
 #define MACHINE_ARCH	"i386"
 #else
 #define MACHINE_ARCH	"unknown"
 #endif
#endif

#if !defined(HARDWARE_PLATFORM)
 #if defined(__OpenBSD__) || (defined(MACHINE_ARCH) && defined(__linux__))
 #define HARDWARE_PLATFORM	MACHINE_ARCH
 #elif defined(__NetBSD__) || defined(__FreeBSD__)
 #define HARDWARE_PLATFORM	"GENERIC"
 #else
 #define HARDWARE_PLATFORM	"unknown"
 #endif
#endif

#if !defined(OS_NAME)
 #if defined(__linux__)
 #define OS_NAME	"GNU/Linux"
 #elif defined(__OpenBSD__)
 #define OS_NAME	"OpenBSD"
 #elif defined(__NetBSD__)
 #define OS_NAME	"NetBSD"
 #elif defined(__FreeBSD__)
 #define OS_NAME	"FreeBSD"
 #elif defined(__APPLE__)
 #define OS_NAME	"macOS"
 #else
 #define OS_NAME	uts.sysname
 #endif
#endif

#endif
