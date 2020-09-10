#include "loop.h"

void shellLoop()
{
    cmdString = readCmd();

    addHistory(cmdString);

    parsedCmd = parseCmd(cmdString);

    executeShell();
}