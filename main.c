#include "dependencies.h"

int main()
{
    clearScreen();
    setRootDirectory(getCurrentAbsolutePath());
    setHistoryFile(getCurrentAbsolutePath());

    while (1)
    {
        presentPrompt();

        shellLoop();
    }
    return 1;
}