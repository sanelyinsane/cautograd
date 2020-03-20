#include <stdio.h>
#include <stdlib.h>
#include "src/n_core.h"
#include "src/n_math.h"


int main() {
        long shape[2] = {2, 2};
        double data[4] = {1.0, 2.0, 3.0, 4.0};

        NDARR *a = create_ones(2, shape);
        NDARR *b = create_ndarr(2, shape, data);
        NDARR *c;

        c = add(a, b);
        n_mul(c, c, b);
        n_sub(b, a, b);

        for (int i = 0; i < b->size; i++) {
                printf("%.2f ", b->data[i]);
        }
        printf("\n");

        free_ndarr(a);
        free_ndarr(b);
        free_ndarr(c);

        return 0;
}
