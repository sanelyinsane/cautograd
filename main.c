#include <stdio.h>
#include <stdlib.h>
#include "src/n_core.h"
#include "src/n_math.h"


int main() {
        long *shape = int_arr_from_arglist(
                2,    // number of dims
                2, 3  // the shape
        );

        NDARR *a = create_ones(2, shape);
        NDARR *b = create_ones(2, shape);
        NDARR *c;

        c = add(a, b);
        n_mul(c, c, b);
        n_sub(b, a, b);

        for (int i = 0; i < a->size; i++) 
                printf("%.2f ", b->data[i]);
        printf("\n");

        printf("Hello dunia !");

        return 0;
}
