#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool
isin_array(char *find, char **where)
{
        for (int i = 0; where[i] != NULL; i++) {
                if (!strcmp(where[i], find))
                        return true;
        }

        return false;
}
