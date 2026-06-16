#include <pwd.h>
#include <err.h>
#include <stdio.h>
#include <string.h>

static uid_t user_from_uid_bef_uid;
static char user_from_uid_bef_username[128];

const char
*user_from_uid(uid_t uid, int nouser)
{
	if (user_from_uid_bef_uid == uid)
		return user_from_uid_bef_username;
	
	struct passwd *pw = getpwuid(uid);
	if (!pw)
		err(1, "getpwuid");
	snprintf(user_from_uid_bef_username, sizeof(user_from_uid_bef_username), "%s", pw->pw_name);
	user_from_uid_bef_uid = uid;

	if (nouser && user_from_uid_bef_username[0] == '\0')
		return NULL;

	if (!nouser && user_from_uid_bef_username[0] != '\0')
		snprintf(user_from_uid_bef_username, sizeof(user_from_uid_bef_username), "%u", uid);

	return user_from_uid_bef_username;
}

static char uid_from_user_bef_username[128];
static uid_t uid_from_user_bef_uid;

int
uid_from_user(const char *name, uid_t *uid)
{
	if (!strcmp(name, uid_from_user_bef_username))	{
		*uid = user_from_uid_bef_uid;
		return 0;
	}

	struct passwd *pw = getpwnam(name);
	if (!pw)
		return 1;
	*uid = pw->pw_uid;
	uid_from_user_bef_uid = *uid;
	snprintf(uid_from_user_bef_username, sizeof(uid_from_user_bef_username), "%s", name);
	return 0;	
	
}
