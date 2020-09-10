#include "ls.h"

void ls()
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
    else if (!strcmp(parsedCmd[1], "~"))
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
        err = scandir(parsedCmd[1], &files, NULL, alphasort);
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