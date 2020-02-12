#include <stdio.h>
int main()
{
    printf("parent: %d", getpid());
    fork(); /* A */
    ( fork()  /* B */ && fork()  /* C */ ) || /* B and C are grouped according to precedence */
    fork(); /* D */
    fork(); /* E */

    printf("pid: %d\n", getpid());
    return 0;
}