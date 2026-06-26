#ifndef _NB_SYS_PARAM_H
#define _NB_SYS_PARAM_H	1

#include_next <sys/param.h>

#if !defined(MACHINE_ARCH)
 #if defined(__x86_64__) || defined(__i386__)
 #define MACHINE_ARCH	"x86"
 #else
 #define MACHINE_ARCH	"unknown"
 #endif
#endif

#if !defined(MACHINE)
 #if defined(__x86_64__)
 #define MACHINE	"amd64"
 #elif defined(__i386__)
 #define MACHINE	"i386"
 #else
 #define MACHINE	"unknown"
 #endif
#endif

#define OS_NAME	"GNU/Linux"
#endif
