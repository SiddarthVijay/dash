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

void filePermissionsDisplay(struct stat fileDesc)
{
    printf("%1s", (S_ISDIR(fileDesc.st_mode)) ? "d" : "-");
    printf("%1s", (fileDesc.st_mode & S_IRUSR) ? "r" : "-");
    printf("%1s", (fileDesc.st_mode & S_IWUSR) ? "w" : "-");
    printf("%1s ", (fileDesc.st_mode & S_IXUSR) ? "x" : "-");
    printf("%1s", (fileDesc.st_mode & S_IRGRP) ? "r" : "-");
    printf("%1s", (fileDesc.st_mode & S_IWGRP) ? "w" : "-");
    printf("%1s ", (fileDesc.st_mode & S_IXGRP) ? "x" : "-");
    printf("%1s", (fileDesc.st_mode & S_IROTH) ? "r" : "-");
    printf("%1s", (fileDesc.st_mode & S_IWOTH) ? "w" : "-");
    printf("%1s ", (fileDesc.st_mode & S_IXOTH) ? "x" : "-");
}

void ownerGroupDescriptions(struct stat fileDesc)
{
    printf("%2lld  ", (long long)(fileDesc.st_nlink));
    printf("%s  ", (getpwuid(fileDesc.st_uid))->pw_name);
    printf("%s  ", (getgrgid(fileDesc.st_gid))->gr_name);
    printf("%7lld  ", (long long)fileDesc.st_size);
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

    struct stat fileDesc;

    for (long long int i = 0; i < err; i++)
    {
        if (isA == 0)
        {
            if (files[i]->d_name[0] == '.')
                continue;
        }
        if (stat(files[i]->d_name, &fileDesc) == 0)
        {
            filePermissionsDisplay(fileDesc);
            ownerGroupDescriptions(fileDesc);

            char clock[15];
            strftime(clock, 15, "%h %d %H:%M", localtime(&fileDesc.st_mtime));
            printf("%s  ", clock);
            printf("%s \n", files[i]->d_name);
        }
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
        else if (!strcmp(parsedCmd[1], "-l"))
        {
            lsL(0, 2);
        }
        else if (!strcmp(parsedCmd[1], "-al"))
        {
            lsL(1, 2);
        }
        else if (!strcmp(parsedCmd[1], "-la"))
        {
            lsL(1, 2);
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