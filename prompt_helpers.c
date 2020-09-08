#include "prompt.h"
#include "helpers.h"
#include "globalconstants.h"

struct utsname UName;
char *CURRENT_SYSTEM;
char *CURRENT_USER;

// Returns system name
char *getSystemName()
{
    int err = uname(&UName);
    if (err != 0)
    {
        perror("Error getting system name: ");
        exit(1);
    }

    CURRENT_SYSTEM = UName.nodename;
    receivedCheck(CURRENT_SYSTEM);

    return CURRENT_SYSTEM;
}

// Returns current username
char *getCurrentUser()
{
    CURRENT_USER = getenv("USER"); // gets username
    receivedCheck(CURRENT_USER);

    return CURRENT_USER;
}

char *getCurrentAbsolutePath()
{
    char *abslouteCWD = malloc(BIG_SIZE * sizeof(char));
    getcwd(abslouteCWD, BIG_SIZE);

    return abslouteCWD;
}

// //ABS_PATH
// valid_check = getcwd(ABS_PATH, 1000000);
// validity(valid_check);

// //REL_PATH
// DIR *directory;
// directory = opendir(ABS_PATH);
// if (directory == NULL)
// {
//     perror("Error : ");
// }