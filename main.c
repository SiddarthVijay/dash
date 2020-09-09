#include "dependencies.h"

int main()
{
    clearScreen();
    setRootDirectory(getCurrentAbsolutePath());

    while (1)
    {
        presentPrompt();
        shellLoop();
    }
    return 1;
}