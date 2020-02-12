#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main(void)
{

        int n = 0;
        int max_n = 2;
        int *numbers = malloc(max_n * sizeof(int));
        if (numbers == NULL)
                return -1;

        while (scanf("%d \n", &numbers[n]) == 1) {
                if (++n == max_n) {
                        max_n *= 2;
                        numbers = realloc(numbers, max_n * sizeof(int));
                        if (numbers == NULL)
                                return -1;
                }
        }

        return 0;
}
