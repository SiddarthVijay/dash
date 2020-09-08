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
    return 1;
}