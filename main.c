#include "dependencies.h"

int main()
{
    setRootDirectory(getCurrentAbsolutePath());
    clearScreen();
    printf("%s", getCurrentAbsolutePath());
    printf("\n");
    printf("%s", getRelativeToRootPath(getCurrentAbsolutePath()));
    return 1;
}