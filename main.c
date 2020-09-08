#include "dependencies.h"

int main()
{
    clearScreen();
    printf("%s", getSystemName());
    printf("%s", getCurrentUser());
    return 1;
}