#include "dependencies.h"

int main()
{
    setRootDirectory(getCurrentAbsolutePath());

    clearScreen();

    presentPrompt();
    return 1;
}