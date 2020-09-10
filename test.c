#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libraries.h"

char *readCmd()
{
    int cmd_size = 0;
    char *cmd = NULL;
    getline(&cmd, &cmd_size, stdin);

    return cmd;
}

char *getCurrentAbsolutePath()
{
    char *abslouteCWD = malloc(1000 * sizeof(char));
    getcwd(abslouteCWD, 1000);

    return abslouteCWD;
}

char *outFile;

void addHistory(char *cmd)
{

    strcat(outFile, "/.history");
    printf("%s", outFile);

    FILE *fptr;

    fptr = fopen(outFile, "a+");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fprintf(fptr, "%s", cmd);
    fclose(fptr);
}

void printHistory(int n)
{
    FILE *file = fopen(outFile, "r");
    if (file != NULL)
    {
        int i = 0;
        char line[128];
        while (fgets(line, sizeof line, file) != NULL)
        {
            if (i >= n)
                break;
            else
                i++;
            fputs(line, stdout);
        }
        fclose(file);
    }
    else
    {
        perror(outFile);
    }
}

int main()
{
    while (1)
    {
        char *test = readCmd();
        outFile = getCurrentAbsolutePath();
        addHistory(test);

        printf("Printing new history:");

        printHistory(10);
    }

    return 1;
}
