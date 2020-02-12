#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "queue.h"

int main(int argc, char **argv)
{
        struct Queue *q = queue_new(sizeof(int));

        int elem = 42;
        queue_put(q, &elem);

        elem = 314159;
        queue_put(q, &elem);

        while (!queue_is_empty(q)) {
                queue_get(q, &elem);
                printf("%d\n", elem);
        }

        queue_free(q);

        return EXIT_SUCCESS;
}
