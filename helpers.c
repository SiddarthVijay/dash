#include "helpers.h"

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