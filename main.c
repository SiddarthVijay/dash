// import "dependencies.h";
#include <stdio.h>
#include <stdlib.h>

#include <sys/utsname.h>

struct utsname UName;
extern char *CUR_SYSTEM;

int main()
{

    // Check UNAME
    int check = uname(&UName); // Uname stores system name
    if (check != 0)
    {
        perror("Error\n");
        exit(1);
    }

    //CUR_SYSTEM
    CUR_SYSTEM = UName.nodename;

    printf("%s", CUR_SYSTEM);

    return 1;
}