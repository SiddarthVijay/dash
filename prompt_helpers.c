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

// Returns cwd
char *getCurrentAbsolutePath()
{
    char *abslouteCWD = malloc(BIG_SIZE * sizeof(char));
    getcwd(abslouteCWD, BIG_SIZE);
    receivedCheck(abslouteCWD);

    return abslouteCWD;
}

// Returns path relative to the shell root dir
char *getRelativeToRootPath(char *path)
{
    char *relativePath = malloc(BIG_SIZE * sizeof(char));

    if (!strcmp(rootDirectory, path))
    {
        strcpy(relativePath, "~");
    }
    else if (strlen(path) < strlen(rootDirectory))
    {
        strcpy(relativePath, path);
    }

    int isDifferent = 0;
    int index = 0;
    for (; index < strlen(rootDirectory); ++index)
    {
        if (rootDirectory[index] != path[index])
        {
            isDifferent = 1;
            break;
        }
    }

    if (isDifferent == 0)
    {
        // Just fixing the warning cuz strcat expects both parameters to be pointers to null-terminated strings
        char temp[1];
        strcpy(relativePath, "~");
        for (; index < strlen(path); ++index)
        {
            temp[0] = path[index];
            strcat(relativePath, temp);
        }
    }

    return relativePath;
}

void presentPrompt(char *path)
{
    CURRENT_SYSTEM = getSystemName();
    CURRENT_USER = getCurrentUser();

    printf("%s%s@%s%s : %s%s ", YELLOW, CURRENT_USER, RED, CURRENT_SYSTEM, CYAN, path);
    printf(RESET);

    return;
}