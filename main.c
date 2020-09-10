#include "dependencies.h"

int main()
{
    clearScreen();
    setRootDirectory(getCurrentAbsolutePath());
    setHistoryFile();

    while (1)
    {
        presentPrompt();

        shellLoop();
    }
    return 1;
}