#include "helpers.h"
#include "prompt.h"
#include "globalconstants.h"
#include "history.h"
#include "pwd.h"

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

void executeShell(char **cmd)
{
    if (cmd[0] == &newline)
        ;
    if (!strcmp(cmd[0], "quit"))
    {
        if (argumentMismatchCheckEqual(1) == 0)
            exit(EXIT_SUCCESS);
    }
    else if (!strcmp(cmd[0], "clear"))
    {
        if (argumentMismatchCheckEqual(1) == 0)
            clearScreen();
    }
    else if (!strcmp(cmd[0], "history"))
    {
        if (argumentMismatchCheckGreater(2) == 0)
        {
            int hisArg;
            if (cmd[1] == NULL)
                hisArg = 10;
            else
                hisArg = atoi(cmd[1]);
            printHistory(hisArg);
        }
    }
    else if (!strcmp(cmd[0], "pwd"))
    {
        if (argumentMismatchCheckEqual(1) == 0)
            printPwd();
    }
    else if (!strcmp(cmd[0], "cd"))
    {
        ;
    }
    return;
}