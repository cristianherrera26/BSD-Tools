#include <string.h>

char *
flags_to_string(unsigned long flags, const char *def)
{
        char string[128];
        const char *prefix;
	(void)flags;
        string[0] = '\0';
        prefix = NULL;
        if (prefix != NULL)
                return strdup(string);
        return strdup(def);
}
