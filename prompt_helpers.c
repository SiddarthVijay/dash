#include "prompt.h"

struct utsname UName;
char *CUR_SYSTEM;

char *getSystemName()
{
    int check = uname(&UName);
    if (check != 0)
    {
        perror("Error getting System Name\n");
        exit(1);
    }

    CUR_SYSTEM = UName.nodename;

    return CUR_SYSTEM;
}