#include <pwd.h>
#include <err.h>
#include <stdio.h>
#include <string.h>

const char
*user_from_uid(uid_t uid, int nouser)
{
	struct passwd *pw = getpwuid(uid);
	char *buf;
	if (!pw)
		err(1, "getpwuid");
	if (!pw->pw_name && nouser)
		return NULL;

	if (!pw->pw_name && !nouser) {
		snprintf(buf, sizeof(buf), "%u", uid);
		return buf;
	}

	return pw->pw_name;
}

int
uid_from_user(const char *name, uid_t *uid)
{
	struct passwd *pw = getpwnam(name);
	if (!pw)
		return 1;
	*uid = pw->pw_uid;
	return 0;	
}
