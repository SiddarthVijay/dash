#include "dependencies.h"

int main()
{
    clearScreen();
    printf("%s", getSystemName());
    printf("%s", getCurrentUser());
    printf("%s", getCurrentAbsolutePath());
    return 1;
}