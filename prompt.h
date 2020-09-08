#include "libraries.h"

char *getSystemName();
char *getCurrentUser();
char *getCurrentAbsolutePath();
char *getRelativeToRootPath(char *path);

void presentPrompt(char *path);