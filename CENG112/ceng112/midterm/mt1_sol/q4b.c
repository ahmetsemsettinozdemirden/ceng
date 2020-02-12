#include <stdio.h>
#include <stdlib.h>

int main(void) {
        char *s = malloc(10*sizeof(char));
        *s = 'A';
        for (int i = 1; i < 10; ++i)
                s[i] = s[i-1] + 2;
        s[5] = '\0';
        printf("%s\n", s); // Line 0

        int a[] = { 0, 1, 2, 3, 4 };
        int n = 4;
        while (--n > 0) {
                a[n] += a[n-1];
                printf("%d ", a[n]);
        }
        printf("\n"); // Line 1
        printf("%d\n", a[0]); // Line 2

        int b[3] = { 0, 1, 2 };
        printf("%d %d %d\n", b[0], b[1], b[2]);

        int *p[3] = { &b[1], &b[0], &b[2] };
        printf("%d %d %d\n", *p[0], *p[1], *p[2]); // Line 4
}
