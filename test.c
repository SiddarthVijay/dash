#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BIG_SIZE 1000
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
        strcpy(relativePath, "~");
        for (; index < strlen(path); ++index)
            strcat(relativePath, path[index]);
    }

    return relativePath;
}
