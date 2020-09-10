#include "helpers.h"
#include "prompt.h"
#include "globalconstants.h"
#include "commands.h"

// Clear terminal screen
void clearScreen()
{
    const char *CLEAR_SCREEN = "\e[1;1H\e[2J";
    write(1, CLEAR_SCREEN, 11);
}

// Check if object is received
void receivedCheck(char *var)
{
    if (var == NULL)
    {
        perror("Error retrieving object: ");
        exit(0);
    }
}

void setRootDirectory(char *root)
{
    rootDirectory = root;

    return;
}

void shellSetup()
{
    clearScreen();
    setRootDirectory(getCurrentAbsolutePath());
}

char *readCmd()
{
    int cmd_size = 0;
    char *cmd = NULL;
    getline(&cmd, &cmd_size, stdin);

    return cmd;
}

int newline = 0;
int charBufferSize = 128;

char **tokens;
char *token;

char **parseCmd(char *cmd)
{
    free(tokens);
    token = NULL;

    int charBuffer = charBufferSize;
    tokens = malloc(charBuffer * sizeof(char *));

    if (!tokens)
    {
        fprintf(stderr, "Memory allocation failed while parsing: \n");
        exit(EXIT_FAILURE);
    }

    token = strtok(cmd, DELIMITERS);
    totalArguments = 0;
    while (token != NULL)
    {
        tokens[totalArguments] = token;
        totalArguments++;

        if (totalArguments >= charBuffer)
        {
            charBuffer += charBufferSize;
            tokens = realloc(tokens, charBuffer * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "Memory allocation failed while parsing: \n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, DELIMITERS);
    }
    if (totalArguments != 0)
    {
        tokens[totalArguments] = NULL;
    }
    else
    {
        tokens[0] = &newline;
    }

    return tokens;
}

int argumentMismatchCheckEqual(int correctArgCount)
{
    if (totalArguments != correctArgCount)
    {
        printf("Argument mismatch. Please try again.\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int argumentMismatchCheckGreater(int correctArgCount)
{
    if (totalArguments > correctArgCount)
    {
        printf("Argument mismatch. Please try again.\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int argumentMismatchCheckLesser(int correctArgCount)
{
    if (totalArguments < correctArgCount)
    {
        printf("Argument mismatch. Please try again.\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

void executeShell()
{
    if (parsedCmd[0] == &newline)
        ;
    if (!strcmp(parsedCmd[0], "quit"))
    {
        if (argumentMismatchCheckEqual(1) == 0)
            exit(EXIT_SUCCESS);
    }
    else if (!strcmp(parsedCmd[0], "clear"))
    {
        if (argumentMismatchCheckEqual(1) == 0)
            clearScreen();
    }
    else if (!strcmp(parsedCmd[0], "history"))
    {
        if (argumentMismatchCheckGreater(2) == 0)
        {
            int hisArg;
            if (parsedCmd[1] == NULL)
                hisArg = 10;
            else
                hisArg = atoi(parsedCmd[1]);
            printHistory(hisArg);
        }
    }
    else if (!strcmp(parsedCmd[0], "pwd"))
    {
        if (argumentMismatchCheckEqual(1) == 0)
            printPwd();
    }
    else if (!strcmp(parsedCmd[0], "echo"))
    {
        if (argumentMismatchCheckLesser(2) == 0)
        {
            printEcho();
        }
    }
    else if (!strcmp(parsedCmd[0], "cd"))
    {
        if (argumentMismatchCheckGreater(2) == 0)
        {
            changeDirectory();
        }
    }
    else if (!strcmp(parsedCmd[0], "ls"))
    {
        ls();
    }
    else
    {
        printf("Invalid command\n");
    }

    return;
}