#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void)
{
        for (int i = 0; i < 10; ++i) {
                int c;
                if ((c = getchar()) == EOF)
                        break;
                putchar(c);
        }

        return EXIT_SUCCESS;
}
