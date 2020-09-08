#include "dependencies.h"

int main()
{
    setRootDirectory(getCurrentAbsolutePath());
    clearScreen();
    printf("%s", getSystemName());
    printf("%s", getCurrentUser());
    printf("%s", getCurrentAbsolutePath());
    printf("\n");
    printf("%s", rootDirectory);
    printf("\n");
    printf("%s", getRelativeToRootPath(getCurrentAbsolutePath()));
    return 1;
}