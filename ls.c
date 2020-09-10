#include "ls.h"

void lsNoFlag(int pathIndex)
{
    char tempdir[100000];

    struct dirent **files;
    int err;
    if (totalArguments == 1)
    {
        err = scandir(".", &files, NULL, alphasort);
        if (err < 0)
        {
            perror("Error");
            return;
        }
    }
    else if (!strcmp(parsedCmd[pathIndex], "~"))
    {
        err = scandir(rootDirectory, &files, NULL, alphasort);
        if (err < 0)
        {
            perror("Error");
            return;
        }
    }
    else
    {
        err = scandir(parsedCmd[pathIndex], &files, NULL, alphasort);
        if (err < 0)
        {
            perror("Error");
            return;
        }
    }

    for (long long int i = 0; i < err; i++)
    {
        if (files[i]->d_name[0] == '.')
            continue;
        else
            printf("%s\n", files[i]->d_name);
    }
    free(files);
}

void lsA(int pathIndex)
{
    char tempdir[100000];

    struct dirent **files;
    int err;
    if (totalArguments == 2)
    {
        err = scandir(".", &files, NULL, alphasort);
        if (err < 0)
        {
            perror("Error");
            return;
        }
    }
    else if (!strcmp(parsedCmd[pathIndex], "~"))
    {
        err = scandir(rootDirectory, &files, NULL, alphasort);
        if (err < 0)
        {
            perror("Error");
            return;
        }
    }
    else
    {
        err = scandir(parsedCmd[pathIndex], &files, NULL, alphasort);
        if (err < 0)
        {
            perror("Error");
            return;
        }
    }

    for (long long int i = 0; i < err; i++)
    {
        printf("%s\n", files[i]->d_name);
        free(files[i]);
    }
    free(files);
}

void lsL(int isA, int pathIndex)
{
    char tempdir[100000];

    struct dirent **files;
    int err;
    if (totalArguments == 2)
    {
        err = scandir(".", &files, NULL, alphasort);
        if (err < 0)
        {
            perror("Error");
            return;
        }
    }
    else if (!strcmp(parsedCmd[pathIndex], "~"))
    {
        err = scandir(rootDirectory, &files, NULL, alphasort);
        if (err < 0)
        {
            perror("Error");
            return;
        }
    }
    else
    {
        err = scandir(parsedCmd[pathIndex], &files, NULL, alphasort);
        if (err < 0)
        {
            perror("Error");
            return;
        }
    }

    for (long long int i = 0; i < err; i++)
    {
        if (isA)
        {
            if (files[i]->d_name[0] == '.')
                continue;
        }
        else
            printf("%s\n", files[i]->d_name);
    }
    free(files);
}

void lsChooser()
{

    if (totalArguments > 1)
    {
        if (!strcmp(parsedCmd[1], "-a"))
        {
            lsA(2);
        }
        else
        {
            lsNoFlag(1);
        }
    }
    else
    {
        lsNoFlag(1);
    }

    return;
}