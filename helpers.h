#include "libraries.h"

void clearScreen();
void receivedCheck();
void setRootDirectory(char *);
char *readCmd();
char **parseCmd(char *);
void executeShell(char **);
