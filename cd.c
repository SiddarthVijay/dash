#include "cd.h"

char *destDir[1000];

void changeDirectory()
{
    // Argument mismatch stays in the same dir
    if (totalArguments != 2)
        return;

    // Single character inputs
    if (!strcmp(parsedCmd[1], "~"))
    {
        int err = chdir(rootDirectory);
        if (err == -1)
            perror("Directory error");

        return;
    }
    else if (!strcmp(parsedCmd[1], "."))
    {
        return;
    }

    strcpy(destDir, getCurrentAbsolutePath());
    strcat(destDir, "/");
    strcat(destDir, parsedCmd[1]);

    int err = chdir(destDir);
    if (err == -1)
        perror("Directory error");

    return;
}