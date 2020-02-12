#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "queue.h"

int main(int argc, char **argv)
{
        struct Queue *q = queue_new(sizeof(char *));

        char *s1 = "That is no moon";
        char *s2 = "I have a bad feeling about this";

        queue_put(q, &s1);
        queue_put(q, &s2);

        char *s_long = NULL;
        int l = 0;
        while (!queue_is_empty(q)) {
                char *s;
                queue_get(q, &s);

                int ls = strlen(s);
                if (ls > l) {
                        l = ls;
                        s_long = s;
                }
        }

        printf("Longest string is \"%s\"\n", s_long);

        queue_free(q);

        return EXIT_SUCCESS;
}
