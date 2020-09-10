#include "libraries.h"
#include "echo.h"

void printEcho()
{
    for (int i = 0; i < totalArguments; i++)
    {
        if (i == 0)
            continue;
        printf("%s ", parsedCmd[i]);
    }

    printf("\n");
}
