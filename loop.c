#include "loop.h"

void shellLoop()
{
    char *cmdString;
    char **parseCmd;
    cmdString = readCmd();
    parseCmd = parsedCmd(cmdString);
    executeShell(parsedCmd);
}