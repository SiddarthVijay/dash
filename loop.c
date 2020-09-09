#include "loop.h"

void shellLoop()
{
    char *cmdString;
    char **parsedCmd;
    cmdString = readCmd();
    parsedCmd = parseCmd(cmdString);
    executeShell(parsedCmd);
}