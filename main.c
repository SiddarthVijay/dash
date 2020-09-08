#include "dependencies.h"

int main()
{
    clearScreen();
    printf("%s", getRelativeToRootPath(getCurrentAbsolutePath()));

    return 1;
}