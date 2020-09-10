#include "libraries.h"
#define DELIMITERS " \t\r\n\a"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

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

char *cmdString;
char **parsedCmd;
char *rootDirectory;

int newline = 0;
int charBufferSize = 128;

char **tokens;
char *token_pointers;
int totalArguments;

char **parseCmd(char *cmd)
{
    free(tokens);
    token_pointers = NULL;

    // Allocate buffer size and memory
    int charBuffer = charBufferSize;
    tokens = malloc(charBuffer * sizeof(char *));

    // check_validity_parse(tokens);

    // Split input line into words
    // token_pointers --> gives the pointers to beginning of each token
    // tokens --> saves the list of pointers in array of pointers
    token_pointers = strtok(cmd, DELIMITERS);
    totalArguments = 0;
    while (token_pointers != NULL)
    {
        tokens[totalArguments] = token_pointers;
        totalArguments++;

        // Reallocate memory when necessary
        if (totalArguments >= charBuffer)
        {
            charBuffer += charBufferSize;
            tokens = realloc(tokens, charBuffer * sizeof(char *));
            // check_validity_parse(tokens);
        }

        token_pointers = strtok(NULL, DELIMITERS);
    }
    if (totalArguments == 0)
    {
        tokens[0] = &newline;
    }
    else
    {
        tokens[totalArguments] = NULL;
    }
    return tokens;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
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

int main()
{
    rootDirectory = getCurrentAbsolutePath();
    cmdString = readCmd();

    parsedCmd = parseCmd(cmdString);

    ls();

    return 1;
}