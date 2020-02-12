#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main(void)
{
        int nw = 0;
        int in_word = 0;
        int c;

        while ((c = getchar()) != EOF) {
                if (c == ' ' || c == '\t' || c == '\n') {
                        if (in_word == 1) {
                                in_word = 0;
                                if (nw >= 10)
                                        break;
                        }
                } else {
                        if (in_word == 0) {
                                in_word = 1;
                                ++nw;
                                c = toupper(c);
                        }
                }

                putchar(c);
        }


        return EXIT_SUCCESS;
}
