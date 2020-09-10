#include "loop.h"

void shellLoop()
{
    char *cmdString;
    char **parsedCmd;

    cmdString = readCmd();

    addHistory(cmdString);

    parsedCmd = parseCmd(cmdString);

    executeShell(parsedCmd);
}