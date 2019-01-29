#include <stdio.h>

main()
{
    execl("/bin/ls", "ls", "-l", 0);
    printf("You can only get here on error\n");
}