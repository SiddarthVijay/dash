#include "history.h"

void setHistoryFile(void *root)
{
    historyFile = root;
    strcat(historyFile, "/.history");

    return;
}

void addHistory(char *cmd)
{
    FILE *fptr;

    fptr = fopen(historyFile, "a+");
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
    FILE *file = fopen(historyFile, "r");
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
        perror(historyFile);
    }
}