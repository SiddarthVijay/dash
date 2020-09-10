#include "libraries.h"

void clearScreen();
void receivedCheck();
void setRootDirectory(char *);
char *readCmd();
char **parseCmd(char *);
int argumentMismatchCheckEqual(int);
int argumentMismatchCheckGreater(int);
void executeShell(char **);
