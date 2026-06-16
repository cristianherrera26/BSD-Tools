#ifndef _NB_PWD_H
#define _NB_PWD_H	1

#include_next <pwd.h>

int uid_from_user(const char *name, uid_t *uid);
const char *user_from_uid(uid_t uid, int nouser);

#endif
