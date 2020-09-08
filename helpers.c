#include "helpers.h"

void clearScreen()
{
    const char *CLEAR_SCREEN = "\e[1;1H\e[2J";
    write(1, CLEAR_SCREEN, 11);
}