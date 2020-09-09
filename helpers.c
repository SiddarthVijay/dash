#include "helpers.h"
#include "prompt.h"
#include "globalconstants.h"

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

char **parseCmd(char *cmd)
{
}

void executeShell(char **cmd)
{
    return;
}